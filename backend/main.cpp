#include <httplib.h>
#include <nlohmann/json.hpp>

#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using json = nlohmann::json;

// ---------------------------
// Run command and capture output (Windows)
// ---------------------------
static std::string run_command(const std::string& cmd)
{
    std::string result;

    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe) return "";

    char buffer[4096];
    while (fgets(buffer, sizeof(buffer), pipe))
    {
        result += buffer;
    }

    _pclose(pipe);
    return result;
}

// ---------------------------
// Docker: get containers list
// ---------------------------
static json get_docker_containers()
{
    std::string cmd =
        "docker ps -a --format \"{{.ID}}|{{.Names}}|{{.Image}}|{{.Status}}\"";

    std::string out = run_command(cmd);

    json arr = json::array();

    std::istringstream iss(out);
    std::string line;

    while (std::getline(iss, line))
    {
        if (line.empty()) continue;

        std::vector<std::string> parts;
        std::stringstream ss(line);
        std::string item;

        while (std::getline(ss, item, '|'))
        {
            parts.push_back(item);
        }

        if (parts.size() < 4) continue;

        json obj;
        obj["id"] = parts[0];
        obj["name"] = parts[1];
        obj["image"] = parts[2];
        obj["status"] = parts[3];

        arr.push_back(obj);
    }

    return arr;
}

int main()
{
    httplib::Server server;

    // Serve frontend folder
    // IMPORTANT: backend exe runs inside backend folder
    // so frontend path should be: ../frontend
    server.set_mount_point("/", "../frontend");

    // API: containers list
    server.Get("/api/containers", [](const httplib::Request&, httplib::Response& res) {

        json data;
        data["ok"] = true;
        data["containers"] = get_docker_containers();

        res.set_content(data.dump(2), "application/json");
    });

    std::cout << "Frontend: http://localhost:8080\n";
    std::cout << "API:      http://localhost:8080/api/containers\n";

    server.listen("0.0.0.0", 8080);
    return 0;
}

# 🐳 Docker Container Monitor

<div align="center">

![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?style=for-the-badge&logo=css3&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white)
![WebSocket](https://img.shields.io/badge/WebSocket-010101?style=for-the-badge&logo=socket.io&logoColor=white)

**A real-time Docker container monitoring application with beautiful web interface**

![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey.svg)
![C++](https://img.shields.io/badge/C++-17-blue.svg)
![Docker](https://img.shields.io/badge/Docker-API%20v1.41-2496ED.svg)

</div>


---

## 🎯 Overview

Docker Container Monitor is a lightweight, efficient monitoring solution that provides:
- 📊 **Real-time container statistics** (CPU, Memory, Network)
- 🎮 **Container management** (Start, Stop, Restart)
- 📄 **Log viewing** capabilities
- 🎨 **Beautiful, responsive** web interface
- 💾 **No database required** - all data is in-memory or from Docker API

Perfect for developers, DevOps engineers, and anyone who needs to monitor Docker containers on their local machine or servers.

---

## ✨ Features

<table>
<tr>
<td width="50%">

### Backend Features
- ✅ Docker API Integration
- ✅ RESTful API
- ✅ WebSocket Support
- ✅ Container Management
- ✅ Log Retrieval
- ✅ Statistics Monitoring
- ✅ Cross-platform

</td>
<td width="50%">

### Frontend Features
- ✅ Modern UI Design
- ✅ Real-time Updates
- ✅ Responsive Layout
- ✅ Container Cards
- ✅ Progress Bars
- ✅ Modal Log Viewer
- ✅ Auto-reconnect

</td>
</tr>
</table>

### 🔧 Technical Features
- 🚀 **No Database** - Lightweight and simple
- ⚡ **In-memory Processing** - Fast performance
- 🌐 **Built-in HTTP Server** - No external web server needed
- 📡 **JSON API** - Standard data format
- 🔀 **Multi-threaded** - Handles multiple connections efficiently
- 🔄 **Auto-refresh** - Statistics update every 2 seconds

---

## 🏗️ Architecture

```
┌─────────────────────────────────────────────────────────────┐
│                         Browser                              │
│  ┌─────────────┐  ┌──────────────┐  ┌──────────────┐       │
│  │   HTML      │  │     CSS      │  │  JavaScript  │       │
│  │ (UI Layer)  │  │  (Styling)   │  │   (Logic)    │       │
│  └─────────────┘  └──────────────┘  └──────────────┘       │
└────────────────────────┬────────────────────────────────────┘
                         │ HTTP/WebSocket
                         │
┌────────────────────────▼────────────────────────────────────┐
│                   C++ Backend Server                         │
│  ┌──────────────────────────────────────────────────────┐   │
│  │              HTTP Server (Crow Framework)            │   │
│  │  ┌────────────────┐        ┌─────────────────────┐  │   │
│  │  │  REST API      │        │   WebSocket Server  │  │   │
│  │  │  Endpoints     │        │   (Real-time stats) │  │   │
│  │  └────────────────┘        └─────────────────────┘  │   │
│  └──────────────────────────────────────────────────────┘   │
│  ┌──────────────────────────────────────────────────────┐   │
│  │           Docker Client (libcurl + API)              │   │
│  │  • List Containers    • Get Stats    • Get Logs      │   │
│  │  • Start/Stop/Restart • Inspect      • Monitor       │   │
│  └──────────────────────────────────────────────────────┘   │
└────────────────────────┬────────────────────────────────────┘
                         │ Docker API
                         │ (Unix socket / TCP)
┌────────────────────────▼────────────────────────────────────┐
│                    Docker Daemon                             │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐   │
│  │Container1│  │Container2│  │Container3│  │Container4│   │
│  └──────────┘  └──────────┘  └──────────┘  └──────────┘   │
└─────────────────────────────────────────────────────────────┘
```

### Data Flow

1. **Browser** → Sends HTTP requests to backend
2. **Backend** → Processes requests and calls Docker API
3. **Docker API** → Returns container information
4. **Backend** → Formats data as JSON and sends to browser
5. **WebSocket** → Continuously streams real-time statistics
6. **Frontend** → Updates UI with new data

---

## 📁 Project Structure

```
docker-monitor/
│
├── backend/                          # C++ Backend Application
│   ├── main.cpp                      # Main server file with routes
│   ├── docker_client.hpp             # Docker API client header
│   ├── docker_client.cpp             # Docker API client (Linux/Unix socket)
│   ├── docker_client_windows.cpp     # Docker API client (Windows/TCP)
│   ├── CMakeLists.txt                # Build configuration (Linux)
│   └── CMakeLists_Windows.txt        # Build configuration (Windows)
│
├── frontend/                         # Web Frontend
│   ├── index.html                    # Main HTML page
│   ├── style.css                     # Styling and animations
│   └── app.js                        # JavaScript logic and WebSocket
│
├── build.bat                         # Windows build script
├── start_monitor.bat                 # Windows launcher script
├── setup.sh                          # Linux setup script
│
├── README.md                         # This file
├── WINDOWS_SETUP.md                  # Detailed Windows setup guide
└── WINDOWS_QUICK_START.md            # Windows quick reference
```

---

## 📦 Prerequisites

### Windows Prerequisites

<details>
<summary><b>Click to expand Windows requirements</b></summary>

#### Required Software

1. **Windows 10/11 (64-bit)**
   - Version: 1909 or later
   - Minimum 8GB RAM (16GB recommended)
   - 10GB free disk space

2. **Docker Desktop for Windows**
   - Version: 4.0 or later
   - Download: https://www.docker.com/products/docker-desktop/
   - ⚠️ Must enable: "Expose daemon on tcp://localhost:2375 without TLS"

3. **Visual Studio 2022 Community Edition** (Free)
   - Workload: "Desktop development with C++"
   - Components:
     - C++ CMake tools for Windows
     - Windows 10/11 SDK
     - MSVC v143 or later
   - Download: https://visualstudio.microsoft.com/downloads/

4. **Git for Windows**
   - Version: 2.30 or later
   - Download: https://git-scm.com/download/win

5. **vcpkg (C++ Package Manager)**
   - Repository: https://github.com/Microsoft/vcpkg

#### Required Libraries (via vcpkg)

- `libcurl` - HTTP client library
- `Boost` - C++ libraries
- `nlohmann-json` - JSON parsing library
- `Crow` - Web framework (header-only)

</details>

### Linux Prerequisites

<details>
<summary><b>Click to expand Linux requirements</b></summary>

#### Required Software

1. **Linux Distribution**
   - Ubuntu 20.04/22.04 LTS (recommended)
   - Debian 10/11
   - Fedora 35+
   - Any modern Linux with Docker support

2. **Docker**
   - Version: 20.10 or later
   - Installation: https://docs.docker.com/engine/install/

3. **Build Tools**
   - GCC 9+ or Clang 10+
   - CMake 3.10+
   - Make

#### Required Libraries

```bash
# Ubuntu/Debian
sudo apt-get install -y \
    build-essential \
    cmake \
    libcurl4-openssl-dev \
    libboost-all-dev \
    git \
    wget

# Fedora/RHEL
sudo dnf install -y \
    gcc-c++ \
    cmake \
    libcurl-devel \
    boost-devel \
    git \
    wget

# Arch Linux
sudo pacman -S \
    base-devel \
    cmake \
    curl \
    boost \
    git \
    wget
```

</details>

---

## 🚀 Installation

### Windows Installation

<details>
<summary><b>Click to expand Windows installation steps</b></summary>

#### Step 1: Install Docker Desktop

1. Download from https://www.docker.com/products/docker-desktop/
2. Run installer and choose "Use WSL 2 instead of Hyper-V"
3. Restart computer
4. Start Docker Desktop
5. **Critical:** Enable TCP endpoint
   - Settings → General
   - ✅ "Expose daemon on tcp://localhost:2375 without TLS"
   - Apply & Restart

#### Step 2: Install Visual Studio 2022

1. Download from https://visualstudio.microsoft.com/downloads/
2. Select "Desktop development with C++"
3. Add components: C++ CMake tools, Windows SDK
4. Install (20-30 minutes)
5. Restart computer

#### Step 3: Install Git for Windows

1. Download from https://git-scm.com/download/win
2. Install with default settings
3. Verify: `git --version`

#### Step 4: Setup vcpkg

```powershell
# Open PowerShell as Administrator
cd C:\
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat
.\vcpkg integrate install
```

#### Step 5: Install Libraries

```powershell
cd C:\vcpkg

# Install curl (5-10 minutes)
.\vcpkg install curl:x64-windows

# Install Boost (20-30 minutes)
.\vcpkg install boost:x64-windows

# Install nlohmann-json (2-3 minutes)
.\vcpkg install nlohmann-json:x64-windows

# Verify
.\vcpkg list
```

#### Step 6: Clone Crow Framework

```powershell
cd C:\
mkdir projects
cd projects
git clone https://github.com/CrowCpp/Crow.git
```

#### Step 7: Setup Project

```powershell
cd C:\projects
# Extract/copy docker-monitor folder here
```

</details>

### Linux Installation

<details>
<summary><b>Click to expand Linux installation steps</b></summary>

#### Step 1: Install Docker

```bash
# Ubuntu/Debian
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
sudo usermod -aG docker $USER
# Log out and back in

# Verify
docker --version
docker ps
```

#### Step 2: Install Build Tools

```bash
# Ubuntu/Debian
sudo apt-get update
sudo apt-get install -y \
    build-essential \
    cmake \
    libcurl4-openssl-dev \
    libboost-all-dev \
    git \
    wget

# Verify
gcc --version
cmake --version
```

#### Step 3: Install Header Libraries

```bash
# Install nlohmann/json
cd /tmp
wget https://github.com/nlohmann/json/releases/download/v3.11.2/json.hpp
sudo mkdir -p /usr/local/include/nlohmann
sudo cp json.hpp /usr/local/include/nlohmann/

# Install Crow
cd /tmp
git clone https://github.com/CrowCpp/Crow.git
sudo cp -r Crow/include/crow /usr/local/include/
```

#### Step 4: Setup Project

```bash
mkdir -p ~/projects/docker-monitor
cd ~/projects/docker-monitor
# Copy project files here
```

</details>

---

## 🔨 Building the Project

### Windows Build

<details>
<summary><b>Windows build instructions</b></summary>

#### Method 1: Automated Build

```powershell
cd C:\projects\docker-monitor
.\build.bat
```

#### Method 2: Manual Build

```powershell
cd C:\projects\docker-monitor\backend

# Important: Use Windows files
copy CMakeLists_Windows.txt CMakeLists.txt
copy docker_client_windows.cpp docker_client.cpp

# Create build directory
mkdir build
cd build

# Configure
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake

# Build
cmake --build . --config Release

# Executable at: Release\docker_monitor.exe
```

</details>

### Linux Build

<details>
<summary><b>Linux build instructions</b></summary>

#### Method 1: Automated Build

```bash
cd ~/projects/docker-monitor
chmod +x setup.sh
./setup.sh
```

#### Method 2: Manual Build

```bash
cd ~/projects/docker-monitor/backend

# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
make -j$(nproc)

# Executable at: ./docker_monitor
```

</details>

---

## ▶️ Running the Application

### Windows

```powershell
# Ensure Docker Desktop is running
docker ps

# Run the monitor
cd C:\projects\docker-monitor
.\start_monitor.bat

# Or manually
cd backend\build\Release
.\docker_monitor.exe
```

### Linux

```bash
# Ensure Docker is running
docker ps

# Run the monitor
cd ~/projects/docker-monitor/backend/build
./docker_monitor
```

### Accessing the Interface

Open your browser and navigate to:

```
http://localhost:8080
```

### Creating Test Containers

```bash
# Start test containers
docker run -d --name test-nginx nginx
docker run -d --name test-redis redis
docker run -d --name test-postgres postgres
docker run -d --name test-mysql mysql:latest

# Verify
docker ps
```

---

## 📡 API Documentation

### Base URL

```
http://localhost:8080
```

### REST API Endpoints

<details>
<summary><b>GET /api/containers</b> - List containers</summary>

**Query Parameters:**
- `all` (optional) - Include stopped containers

**Response:**
```json
[
  {
    "Id": "abc123...",
    "Names": ["/test-nginx"],
    "Image": "nginx:latest",
    "State": "running",
    "Status": "Up 2 hours"
  }
]
```

</details>

<details>
<summary><b>GET /api/containers/{id}</b> - Get container details</summary>

**Response:**
```json
{
  "Id": "abc123...",
  "Name": "/test-nginx",
  "State": {
    "Status": "running",
    "Running": true
  },
  "Config": {
    "Image": "nginx:latest"
  }
}
```

</details>

<details>
<summary><b>GET /api/containers/{id}/stats</b> - Get statistics</summary>

**Response:**
```json
{
  "cpu_stats": {
    "cpu_usage": {
      "total_usage": 12345678
    },
    "online_cpus": 4
  },
  "memory_stats": {
    "usage": 52428800,
    "limit": 2147483648
  },
  "networks": {
    "eth0": {
      "rx_bytes": 1024,
      "tx_bytes": 2048
    }
  }
}
```

</details>

<details>
<summary><b>GET /api/containers/{id}/logs</b> - Get logs</summary>

**Query Parameters:**
- `tail` (optional) - Number of lines (default: 100)

**Response:**
```json
{
  "logs": "2024-01-15 10:30:00 Starting nginx...\n"
}
```

</details>

<details>
<summary><b>POST /api/containers/{id}/start</b> - Start container</summary>

**Response:**
```json
{
  "success": true
}
```

</details>

<details>
<summary><b>POST /api/containers/{id}/stop</b> - Stop container</summary>

**Response:**
```json
{
  "success": true
}
```

</details>

<details>
<summary><b>POST /api/containers/{id}/restart</b> - Restart container</summary>

**Response:**
```json
{
  "success": true
}
```

</details>

### WebSocket Endpoint

**Connection:**
```
WS /ws
```

**Message Format:**
```json
{
  "type": "stats",
  "data": [
    {
      "id": "abc123",
      "name": "/test-nginx",
      "state": "running",
      "cpu_percent": 2.5,
      "memory_usage": 50.5,
      "memory_percent": 2.47,
      "network_rx": 1.5,
      "network_tx": 0.8
    }
  ]
}
```

**Update Frequency:** Every 2 seconds

---

## 📖 Usage Guide

### Basic Operations

<table>
<tr>
<td width="50%">

#### 👁️ Viewing Containers
1. Open http://localhost:8080
2. See all running containers
3. Click "Show All" for stopped containers

</td>
<td width="50%">

#### ▶️ Starting a Container
1. Find stopped container card
2. Click green "▶ Start" button
3. Stats appear automatically

</td>
</tr>
<tr>
<td width="50%">

#### ⏹️ Stopping a Container
1. Find running container card
2. Click red "⏹ Stop" button
3. Container stops

</td>
<td width="50%">

#### 🔄 Restarting a Container
1. Find any container card
2. Click orange "🔄 Restart" button
3. Container restarts

</td>
</tr>
<tr>
<td width="50%">

#### 📄 Viewing Logs
1. Click "📄 Logs" button
2. Modal shows last 100 lines
3. Click X to close

</td>
<td width="50%">

#### 📊 Monitoring Stats
Statistics auto-update every 2s:
- CPU Usage (%)
- Memory (MB, %)
- Network RX/TX (MB)

</td>
</tr>
</table>

### Advanced Features

- **Filter Containers**: Toggle "Show All" / "Show Running Only"
- **Manual Refresh**: Click "🔄 Refresh" button
- **Connection Status**: Green = Connected, Red = Disconnected
- **Auto-reconnect**: WebSocket reconnects every 5s if disconnected

---

## ⚙️ Configuration

### Change Server Port

Edit `main.cpp`:

```cpp
// Change from 8080 to your port
app.port(3000).multithreaded().run();
```

Rebuild the project.

### Change Update Interval

Edit `main.cpp` in `broadcastStats` function:

```cpp
// Change from 2 seconds
std::this_thread::sleep_for(std::chrono::seconds(5));
```

Rebuild the project.

### Change Docker Endpoint

**Windows:**
```cpp
DockerClient docker_client("http://localhost:2375");
```

**Linux:**
```cpp
DockerClient docker_client("/var/run/docker.sock");
```

---

## 🐛 Troubleshooting

### Windows Issues

<details>
<summary><b>❌ Cannot connect to Docker API</b></summary>

**Solutions:**

1. Check Docker Desktop is running:
   ```powershell
   docker ps
   ```

2. Enable TCP endpoint:
   - Docker Desktop → Settings → General
   - ✅ "Expose daemon on tcp://localhost:2375 without TLS"
   - Apply & Restart

3. Test API:
   ```powershell
   curl http://localhost:2375/_ping
   ```

4. Check firewall settings

</details>

<details>
<summary><b>❌ CMake cannot find packages</b></summary>

**Solutions:**

```powershell
# Verify packages
C:\vcpkg\vcpkg list

# Reinstall if missing
C:\vcpkg\vcpkg install <package>:x64-windows

# Use toolchain file
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake
```

</details>

<details>
<summary><b>❌ Missing DLL when running</b></summary>

**Solutions:**

```powershell
# Copy DLLs to exe directory
cd C:\projects\docker-monitor\backend\build\Release
copy C:\vcpkg\installed\x64-windows\bin\*.dll .
```

</details>

<details>
<summary><b>❌ Port 8080 already in use</b></summary>

**Solutions:**

1. Find process using port:
   ```powershell
   netstat -ano | findstr :8080
   ```

2. Kill process or change port in main.cpp

</details>

### Linux Issues

<details>
<summary><b>❌ Permission denied accessing Docker socket</b></summary>

**Solutions:**

```bash
# Add user to docker group
sudo usermod -aG docker $USER
# Log out and back in

# Or temporary fix
sudo chmod 666 /var/run/docker.sock

# Or run with sudo (not recommended)
sudo ./docker_monitor
```

</details>

<details>
<summary><b>❌ Cannot find -lcurl</b></summary>

**Solutions:**

```bash
# Ubuntu/Debian
sudo apt-get install libcurl4-openssl-dev

# Fedora
sudo dnf install libcurl-devel

# Arch
sudo pacman -S curl
```

</details>

<details>
<summary><b>❌ crow.h: No such file or directory</b></summary>

**Solutions:**

```bash
# Reinstall Crow
cd /tmp
git clone https://github.com/CrowCpp/Crow.git
sudo cp -r Crow/include/crow /usr/local/include/
```

</details>

### Common Issues

<details>
<summary><b>❌ Frontend not loading</b></summary>

**Solutions:**

1. Check file locations:
   - Executable: `backend/build/Release/` or `backend/build/`
   - Frontend: `frontend/`

2. Server looks for `../frontend/` relative to executable

3. Verify files exist:
   - index.html
   - style.css
   - app.js

</details>

<details>
<summary><b>❌ No containers showing</b></summary>

**Solutions:**

1. Create test containers:
   ```bash
   docker run -d --name test-nginx nginx
   ```

2. Check Docker is running:
   ```bash
   docker ps
   ```

3. Check browser console (F12) for errors

</details>

<details>
<summary><b>❌ Stats not updating</b></summary>

**Solutions:**

1. Check WebSocket connection (browser console)
2. Check "Connection Status" badge
3. Manually refresh with 🔄 button
4. Restart server

</details>

---

## 🛠️ Development

### Adding New Features

<details>
<summary><b>Backend (C++)</b></summary>

1. **Add endpoint** in `main.cpp`:
```cpp
CROW_ROUTE(app, "/api/containers/<string>/pause")
.methods("POST"_method)
([&docker_client](const std::string& id) {
    bool success = docker_client.pauseContainer(id);
    json response;
    response["success"] = success;
    return crow::response(response.dump());
});
```

2. **Add method** to `docker_client.hpp`:
```cpp
bool pauseContainer(const std::string& container_id);
```

3. **Implement** in `docker_client.cpp`:
```cpp
bool DockerClient::pauseContainer(const std::string& container_id) {
    std::string endpoint = "/v1.41/containers/" + container_id + "/pause";
    std::string response = makeRequest(endpoint, "POST");
    return !response.empty();
}
```

</details>

<details>
<summary><b>Frontend (JavaScript)</b></summary>

1. **Add button** in `app.js`:
```javascript
<button id="pause-${id}" class="btn btn-warning">⏸ Pause</button>
```

2. **Add event listener**:
```javascript
document.getElementById(`pause-${id}`)?.addEventListener('click', 
    () => pauseContainer(id));
```

3. **Add function**:
```javascript
async function pauseContainer(id) {
    const response = await fetch(`/api/containers/${id}/pause`, 
        { method: 'POST' });
    const result = await response.json();
    if (result.success) loadContainers();
}
```

</details>

### Code Style Guidelines

- **C++**: camelCase functions, PascalCase classes, snake_case variables
- **JavaScript**: camelCase for functions/variables, async/await for promises
- **CSS**: kebab-case for class names, group related properties

---

## 🙏 Credits

### Technologies Used

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=cplusplus&logoColor=white)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=flat&logo=docker&logoColor=white)
![WebSocket](https://img.shields.io/badge/WebSocket-010101?style=flat&logo=socket.io&logoColor=white)
![JSON](https://img.shields.io/badge/JSON-000000?style=flat&logo=json&logoColor=white)

- **C++17** - Modern C++ standard
- **libcurl** - HTTP client library
- **Crow** - C++ web framework
- **nlohmann/json** - JSON library
- **Boost** - C++ libraries
- **Docker API** - Container management
- **WebSocket** - Real-time communication

### Resources

- [Docker API Documentation](https://docs.docker.com/engine/api/)
- [libcurl Documentation](https://curl.se/libcurl/)
- [WebSocket API](https://developer.mozilla.org/en-US/docs/Web/API/WebSocket)

---

## 🎓 Learning Resources

- **Docker:** [https://docs.docker.com/](https://docs.docker.com/)
- **C++ Best Practices:** [https://isocpp.org/](https://isocpp.org/)
- **REST API Design:** [https://restfulapi.net/](https://restfulapi.net/)
- **WebSocket Protocol:** [RFC 6455](https://datatracker.ietf.org/doc/html/rfc6455)
- **Modern JavaScript:** [https://javascript.info/](https://javascript.info/)

---

<div align="center">

## ⭐ Show Your Support

If you find this project useful, please consider giving it a star!

![GitHub stars](https://img.shields.io/github/stars/yourusername/docker-monitor?style=social)
![GitHub forks](https://img.shields.io/github/forks/yourusername/docker-monitor?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/yourusername/docker-monitor?style=social)

**Built with ❤️ using C++ and modern web technologies**

**Happy Monitoring! 🐳📊**

</div>

---

<div align="center">

![Made with C++](https://img.shields.io/badge/Made%20with-C++-00599C?style=for-the-badge&logo=cplusplus)
![Docker](https://img.shields.io/badge/Powered%20by-Docker-2496ED?style=for-the-badge&logo=docker)
![Open Source](https://img.shields.io/badge/Open-Source-green?style=for-the-badge)

</div>

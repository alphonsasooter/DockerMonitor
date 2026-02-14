async function loadContainers() {
  const status = document.getElementById("status");
  const list = document.getElementById("list");

  status.textContent = "Loading containers...";
  list.innerHTML = "";

  try {
    // For demo purposes, using static containers
    const data = {
      ok: true,
      containers: [
        { id: "abc123", name: "nginx_demo", image: "nginx", status: "Up 10 seconds" },
        { id: "def456", name: "redis_demo", image: "redis", status: "Up 5 minutes" },
        { id: "ghi789", name: "mongo_demo", image: "mongo", status: "Exited (0)" },
        { id: "jkl012", name: "postgres_demo", image: "postgres", status: "Up 2 hours" }
      ]
    };

    if (!data.ok) {
      status.textContent = "❌ Backend returned error";
      return;
    }

    const containers = data.containers;
    if (containers.length === 0) {
      status.textContent = "No containers found.";
      return;
    }

    status.textContent = `✅ Found ${containers.length} containers`;

    containers.forEach(c => {
      const div = document.createElement("div");
      div.className = "card";

      div.innerHTML = `
        <h3>${c.name}</h3>
        <p><b>ID:</b> ${c.id}</p>
        <p><b>Image:</b> ${c.image}</p>
        <p><b>Status:</b> ${c.status}</p>
      `;

      list.appendChild(div);
    });

  } catch (err) {
    status.textContent = "❌ Failed to connect to backend";
  }
}

document.getElementById("refreshBtn").addEventListener("click", loadContainers);
loadContainers();

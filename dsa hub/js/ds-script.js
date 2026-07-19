console.log("JavaScript Loaded!");

// This will store every topic from the JSON
let allTopics = {};

// HTML elements
const topicList = document.getElementById("topic-list");
const topicContent = document.getElementById("topic-content");


// ------------------------------
// Load JSON (topic content)
// ------------------------------

async function loadTopics() {

    try {

        const response = await fetch("content-of-ds.json");

        if (!response.ok) {
            throw new Error("Couldn't load JSON");
        }

        allTopics = await response.json();

        createSidebar();

    }

    catch (error) {

        topicContent.innerHTML =
        "<p>Something went wrong, the file couldn't load.</p>";

        console.error(error);

    }

}

loadTopics();


// ------------------------------
// Load a single .cpp file
// (same pattern as loadCpp in time-complexity.js)
// ------------------------------

async function loadCpp(path) {

    try {

        const response = await fetch(path);

        if (!response.ok) {
            throw new Error("Couldn't load C++ file.");
        }

        const cppCode = await response.text();

        return cppCode;

    }

    catch (error) {

        console.error(error);

        return "// Unable to load code.";

    }

}


// ------------------------------
// Create Sidebar
// ------------------------------

function createSidebar() {

    topicList.innerHTML = "";

    for (const key in allTopics) {

        const li = document.createElement("li");

        li.textContent = allTopics[key].title;

        li.classList.add("topic-item");

        li.addEventListener("click", () => {

            showTopic(key);
            highlightActive(li);

        });

        topicList.appendChild(li);

    }

}


// ------------------------------
// Show a topic (now async, since the .cpp file has to be fetched)
// ------------------------------

async function showTopic(topicKey) {

    const topic = allTopics[topicKey];

    // Show a quick loading message while the .cpp file is fetched
    topicContent.innerHTML = "<p class='placeholder'>Loading...</p>";

    const cppCode = await loadCpp(topic.code);

    topicContent.innerHTML = `

        <h1>${topic.title}</h1>

        <h3>${topic.kicker}</h3>

        <hr>

        <h2>What is it?</h2>
        <p>${topic.whatIsIt}</p>

        <h2>Why use it?</h2>
        <p>${topic.whyUseIt}</p>

        <h2>Real Life Analogy</h2>
        <p>${topic.analogy}</p>

        <h2>Operations</h2>

        <table>

            <tr>

                <th>Operation</th>

                <th>Time Complexity</th>

            </tr>

            ${topic.operations.map(op => `

                <tr>

                    <td>${op.name}</td>

                    <td>${op.complexity}</td>

                </tr>

            `).join("")}

        </table>

        <h2>Types</h2>

        <ul>

            ${topic.types.map(type => `

                <li>

                    <strong>${type.name}</strong><br>

                    ${type.description}

                </li>

            `).join("")}

        </ul>

        <h2>C++ Implementation</h2>

        <pre><code>${escapeHtml(cppCode)}</code></pre>

        <h2>Interview Questions</h2>

        <ol>

            ${topic.interviewQuestions.map(q => `

                <li>${q}</li>

            `).join("")}

        </ol>

    `;

}


// ------------------------------
// Highlight the selected sidebar item
// ------------------------------

function highlightActive(selectedLi) {

    document.querySelectorAll("#topic-list li").forEach((li) => {
        li.classList.remove("active");
    });

    selectedLi.classList.add("active");

}


// ------------------------------
// Escape HTML so C++ code like vector<int> or "a < b"
// renders as text instead of being read as real HTML tags
// ------------------------------

function escapeHtml(text) {
    return text
        .replaceAll("&", "&amp;")
        .replaceAll("<", "&lt;")
        .replaceAll(">", "&gt;");
}
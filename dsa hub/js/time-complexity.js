console.log("JavaScript Connected");

let timeData = [];
let spaceData = [];
let currentType = "time";

const complexityDisplay = document.getElementById("data-shown-here-of-time-complexity");
const timeCard = document.getElementById("time-comp-toggle");
const spaceCard = document.getElementById("space-comp-toggle");


// ----------------------
// Load a JSON file
// ----------------------

async function loadJSON(path) {

    try {

        const response = await fetch(path);

        if (!response.ok) {
            throw new Error(`Couldn't load ${path}`);
        }

        return await response.json();

    }

    catch (error) {

        console.error(error);

        return [];

    }

}


// ----------------------
// Load both datasets, then show Time Complexity by default
// ----------------------

async function loadAllData() {

    timeData = await loadJSON("time-complexity.json");
    spaceData = await loadJSON("space-complexity.json");

    showData("time");

}


// ----------------------
// Load C++ File
// ----------------------

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


// ----------------------
// Escape HTML so code containing < > (like #include <iostream>) renders correctly
// ----------------------

function escapeHTML(str) {

    return str
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;");

}


// ----------------------
// Display Examples for a given type: "time" or "space"
// ----------------------

async function showData(type) {

    currentType = type;

    const dataset = type === "time" ? timeData : spaceData;
    const complexityKey = type === "time" ? "time-complexity" : "space-complexity";
    const complexityLabel = type === "time" ? "Time Complexity" : "Space Complexity";

    // Highlight whichever card is currently active
    timeCard.classList.toggle("active-type", type === "time");
    timeCard.setAttribute("aria-pressed", type === "time");

    spaceCard.classList.toggle("active-type", type === "space");
    spaceCard.setAttribute("aria-pressed", type === "space");

    complexityDisplay.innerHTML = "<p class='loading-msg'>Loading examples...</p>";

    let builtHTML = "";

    // Loop through every object in the chosen dataset

    for (const topic of dataset) {

        // Load cpp file

        const cppCode = await loadCpp(topic.code);

        // Add HTML

        builtHTML += `

            <div class="example-card">

                <h2>${topic.title}</h2>

                <pre><code>${escapeHTML(cppCode)}</code></pre>

                <h3>${complexityLabel}</h3>

                <p>${topic[complexityKey]}</p>

                <h3>Explanation</h3>

                <p>${topic.reason}</p>

            </div>

            <hr>

        `;

    }

    complexityDisplay.innerHTML = builtHTML;

}


// ----------------------
// Click (and keyboard) listeners on the two toggle cards
// ----------------------

timeCard.addEventListener("click", () => showData("time"));
spaceCard.addEventListener("click", () => showData("space"));

timeCard.addEventListener("keydown", (e) => {
    if (e.key === "Enter" || e.key === " ") showData("time");
});

spaceCard.addEventListener("keydown", (e) => {
    if (e.key === "Enter" || e.key === " ") showData("space");
});


loadAllData();
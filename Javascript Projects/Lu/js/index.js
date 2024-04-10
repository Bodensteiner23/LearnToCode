/* ============================= Variables ============================ */
const frankysButton = document.getElementById("frankys_button")


/* ============================= Functions ============================ */
function initEventListeners() {
    if (frankysButton) {
        frankysButton.addEventListener("click", frankysButtonClicked)
    }

}

initEventListeners()


function frankysButtonClicked(event) {
    // Open Frankys Game Page
     location.href = "frankys.html"
}
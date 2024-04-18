/* ============================= Variables ============================ */
const franticButton = document.getElementById("frantic_button")


/* ============================= Functions ============================ */
function initEventListeners() {
    if (franticButton) {
        franticButton.addEventListener("click", franticButtonClicked)
    }

}

initEventListeners()


function franticButtonClicked() {
    // Open Frankys Game Page
     location.href = "frantic.html"
}

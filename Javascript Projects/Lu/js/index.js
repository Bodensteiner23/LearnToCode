/* ============================= Variables ============================ */
const franticButton = document.getElementById("frantic_button")
const kniffelButton = document.getElementById("kniffel_button")


/* ============================= Functions ============================ */
function initEventListeners() {
    if (franticButton) {
        franticButton.addEventListener("click", franticButtonClicked)
    }

    if (kniffel_button) {
        kniffelButton.addEventListener("click", kniffelButtonClicked)
    }
}

initEventListeners()


function franticButtonClicked() {
    // Open Frankys Game Page
    location.href = "html/frantic.html"
}


function kniffelButtonClicked() {
    // Open Kniffel Game Page
    location.href = "html/kniffel/kniffel.html"
}
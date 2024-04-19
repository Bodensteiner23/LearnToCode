
function initEventListeners() {
    const button = document.getElementById("close_button")
    if (button) {
        button.addEventListener("click", closePage)
    }
}

initEventListeners()

function closePage() {

    window.history.back()
}



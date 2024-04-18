
function initEventListeners() {
    const button = document.getElementById("close_button")
    if (button) {
        button.addEventListener("click", closePage)
    }
}

function closePage() {

    window.history.back()
}



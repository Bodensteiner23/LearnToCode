

const field = document.getElementById("snake_map")

let field_size = 25
let field_x = 20
let field_y = 20


function initField() {
    field.width = field_x * field_size
    field.height = field_y * field_size
    
    const ctx = field.getContext("2d")
}

initField()



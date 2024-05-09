const field = document.getElementById("snake_map")
let ctx

let field_size = 25
let field_x = 20
let field_y = 20

const step = {
    x: 1,
    y: 1
}

const snake = {
    x: field_size * step.x,
    y: field_size * step.y

}

function initField() {
    field.width = field_x * field_size
    field.height = field_y * field_size
    
    ctx = field.getContext("2d")
}

initField()

function drawSnake() {
    ctx.fillStyle = "lime"
    ctx.fillRect(snake.x, snake.y, field_size, field_size)

}


drawSnake()
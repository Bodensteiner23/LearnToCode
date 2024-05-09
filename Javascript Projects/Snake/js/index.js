
//board

var fieldsize = 35; 
var x = 20;
var y = 20; 
var schritt = {
    x: 5,
    y: 2,
}
var board;
var ctx;

// create snake
    const snake = {
        x:  fieldsize * schritt.x,
        y:  fieldsize * schritt.y,
        speed: fieldsize,
    }


function init() {
    board = document.getElementById("snake_map");
    board.height = y * fieldsize;
    board.width = x * fieldsize;
    ctx = board.getContext("2d");

    update();

}

init();

function update() {
    ctx.fillStyle = "black";
    ctx.fillRect(0,0,board.height,board.width);

    ctx.fillStyle = "lime";
    ctx.fillRect(snake.x, snake.y, fieldsize, fieldsize);



}


function moveSnake (direction) {
    switch  (direction) {
        case "up":
            snake.y -=snake.speed;
            break; 
    }

} 


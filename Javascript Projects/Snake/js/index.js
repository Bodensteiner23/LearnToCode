
//spielfeld

var feldgröße = 25; 
var x = 20;
var y = 20; 
var brett;
var ctx;



function init() {
    brett = document.getElementById("snake_map");
    brett.height = x * feldgröße;
    brett.width = y * feldgröße;
    ctx = brett.getContext("2d");

    update();

}

init();

function update() {
    ctx.fillSytle="black";
    ctx.fillRect(0,0,brett.height,brett.width);

    ctx.fillSytle="lime"
    ctx.



}



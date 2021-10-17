import World from './modules/world.js';
import Vehicle from './modules/vehicle.js';

let alto = 0, ancho = 0;
let world = new World(ancho, alto);
let vehicle = new Vehicle(0, 0);

$('#alto, #ancho').change(() => {
  world.clear();

  alto = checkNaN($('#alto').val());
  ancho = checkNaN($('#ancho').val());

  world = new World(ancho, alto);

  setInterval(checkclickworld(world), 10);
})

$('#obstaculos_input').change(() => {
  let obstaculos = checkNaN($('#obstaculos_input').val());
  world.setRandObs(obstaculos);
})

$('#x_vehiculo, #y_vehiculo').change(() => {
  vehicle.clear();
  
  let x = checkNaN($('#x_vehiculo').val());
  let y = checkNaN($('#y_vehiculo').val());

  vehicle = new Vehicle(x, y);
})

$('#x_final, #y_final').change(() => {
  vehicle.clearfinal();
  
  let x = checkNaN($('#x_final').val());
  let y = checkNaN($('#y_final').val());

  vehicle.setfinal(x, y);
})

function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

function checkclickworld(world) {
  for (let i = 0; i < world.row; i++) {
    for (let j = 0; j < world.col; j++) {
      let current = $('.row' + i + ' > .col' + j);

      current.mouseout((e) => {
        if (e.buttons == 1) {
          if (world.map[i][j] == 0) {
            current.css('background-color', 'black');
            world.map[i][j] = 1;
          } else {
            current.css('background-color', 'white');
            world.map[i][j] = 0;
          }
        }
      });

      current.click(() => {
        if (world.map[i][j] == '0') {
          current.css('background-color', 'black');
          world.map[i][j] = 1;
        } else {
          current.css('background-color', 'white');
          world.map[i][j] = 0;
        }
      });
    }
  }
}
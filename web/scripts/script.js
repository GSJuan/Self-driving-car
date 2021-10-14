import World from './modules/world.js';
import Vehicle from './modules/vehicle.js';

let alto = 0, ancho = 0, world = new World(ancho, alto);

$('#alto, #ancho').change(() => {
  removeprev(ancho);

  alto = checkNaN($('#alto').val());
  ancho = checkNaN($('#ancho').val());

  world = new World(ancho, alto);

  world.map.forEach((element, i) => {
    var row = "<div class='row" + i + "' id='row'></div>";
    $('.table').append(row);
    element.forEach((element, j) => {
      var col = "<div class='col" + j + "' id='col'></div>";
      $('.row' + i).append(col);
    });
  });

  setInterval(checkclickworld(world), 10);
})

$('#obstaculos_input').change(() => {
  let obstaculos = checkNaN($('#obstaculos_input').val());
  world.setRandObs(obstaculos);
})

function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

function removeprev(ancho) {
  if (ancho === undefined) ancho = 10;
  for (let i = 0; i < ancho; i++) {
    $('.row' + i).remove();
  }
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
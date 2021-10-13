import World from './modules/world.js';
import Vehicle from './modules/vehicle.js';

$('#simular').click(() => {
  let alto = checkNaN($('#alto').val());
  let ancho = checkNaN($('#ancho').val());
  let obstaculos = checkNaN($('#obstaculos_input').val());
  let direcciones = checkNaN($('#direcciones_input').val());
  let x_vehiculo = checkNaN($('#x_vehiculo').val());
  let y_vehiculo = checkNaN($('#y_vehiculo').val());
  let x_final = checkNaN($('#x_final').val());
  let y_final = checkNaN($('#y_final').val());

  removeprev(ancho);

  let world = new World(ancho, alto, obstaculos);

  world.map.forEach((element, i) => {
    var row = "<div class='row" + i + "' id='row' style='background-color: white'></div>";
    $('.table').append(row);
    element.forEach((element, j) => {
      var col = "<div class='col" + j + "' id='col' style='background-color: white'></div>";
      $('.row' + i).append(col);
    });
  });

  setInterval(checkclickworld(world), 10);
});

function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

function removeprev(ancho) {
  for (let i = 0; i < ancho; i++) {
    $('.row' + i).remove();
  }
}

function checkclickworld(world) {
  for (let i = 0; i < world.row; i++) {
    for (let j = 0; j < world.col; j++) {
      let current = $('.row' + i + ' > .col' + j);
      current.click(() => {
        if (current.css('background-color') == 'rgb(255, 255, 255)')
          current.css('background-color', 'black');
        else{
          console.log(current.css('background-color'));
          current.css('background-color', 'white');}
      });
    }
  }
}
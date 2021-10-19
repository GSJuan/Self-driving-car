// Fichero creado para declarar todas las funciones de forma global y exportada

// Checkea si un número intero no es NaN (Not a Number), retorna undefined si lo es, si no, devuelve el número
export function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

// Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
export function checkclickworld(world, vehicle) {
  $('.col').on("mouseout", function (e) {
    if (e.buttons == 1) {
      let i = $(this).parent().attr('id').replace('row', '');
      let j = $(this).attr('id').replace('col', '');
      let current = $('#row' + i + ' > #col' + j);

      if ((vehicle.x != j || vehicle.y != i) && 
        (vehicle.x_final != j || vehicle.y_final != i)) {
          console.log(1)
        if (world.map[i][j] == 0) {
          current.css('background-color', 'black');
          world.map[i][j] = 1;
        } else {
          current.css('background-color', 'white');
          world.map[i][j] = 0;
        }
      }
    }
  });

  $('.col').on("click", function () {
    let i = $(this).parent().attr('id').replace('row', '');
    let j = $(this).attr('id').replace('col', '');
    let current = $('#row' + i + ' > #col' + j);

    if ((vehicle.x != j || vehicle.y != i) && 
        (vehicle.x_final != j || vehicle.y_final != i)) {
          console.log(i, j)
        if (world.map[i][j] == 0) {
          current.css('background-color', 'black');
          world.map[i][j] = 1;
        } else {
          current.css('background-color', 'white');
          world.map[i][j] = 0;
        }
      }
  });
}

// Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
export function checkmovevehicle(vehicle, world) {
  $('.car').on("mouseout", function (e) {
    if (e.buttons == 1) {
      let i = $(this).parent().parent().attr('id').replace('row', '');
      let j = $(this).parent().attr('id').replace('col', '');
      let current = $('#row' + i + ' > #col' + j);
      
      if ((vehicle.x != j || vehicle.y != i) && 
        (vehicle.x_final != j || vehicle.y_final != i)) {
        if (world.map[i][j] == 0) {
          current.css('background-color', 'black');
          world.map[i][j] = 1;
        } else {
          current.css('background-color', 'white');
          world.map[i][j] = 0;
        }
      }
    }
  });
}

// Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
export function checkmovefinal(vehicle, world) {
  $('.car').on("mouseout", function (e) {
    if (e.buttons == 1) {
      let i = $(this).parent().parent().attr('id').replace('row', '');
      let j = $(this).parent().attr('id').replace('col', '');
      let current = $('#row' + i + ' > #col' + j);
      
      if ((vehicle.x != j || vehicle.y != i) && 
        (vehicle.x_final != j || vehicle.y_final != i)) {
        if (world.map[i][j] == 0) {
          current.css('background-color', 'black');
          world.map[i][j] = 1;
        } else {
          current.css('background-color', 'white');
          world.map[i][j] = 0;
        }
      }
    }
  });
}

// Crea un número aleatorio entre min y max
export function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}

export function grid() {
  if ($('#grid').is(":checked"))
    $('.table .col').css('border', '1px solid grey');
  else 
    $('.table .col').css('border', '0px solid grey');
}

export function borderinterval() {
  setInterval(() => {
    setTimeout(() => {
      $('.car').css('background-color', '#528BEB')
      $('.final').css('background-color', '#ff0000')
      $('.car .st0').css('fill', 'black')
      $('.final .st0, .final .st1').css('stroke', 'black')
    }, 1000);
    setTimeout(() => {
      $('.car').css('background-color', 'white')
      $('.final').css('background-color', 'white')
      $('.car .st0').css('fill', '#528BEB')
      $('.final .st0, .final .st1').css('stroke', '#ff0000')
    }, 2000);
  }, 2000)
}
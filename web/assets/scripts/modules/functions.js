// Fichero creado para declarar todas las funciones de forma global y exportada

// Checkea si un número intero no es NaN (Not a Number), retorna undefined si lo es, si no, devuelve el número
export function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

// Checkea si estas clickando en las celdas del tablero o arrastrando el cursor y lo cambia de color
// Para cada celda lo cambia de color en caso de ser click_izq o el mouse salga de la celda pulsando el click izq
export function checkclickworld(world) {
  for (let i = 0; i < world.row; i++) {
    for (let j = 0; j < world.col; j++) {
      let current = $('.row' + i + ' > .col' + j);

      current.on("mouseout", (e) => {
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

      current.on("click", () => {
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

// Crea un número aleatorio entre min y max
export function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}
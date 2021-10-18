import * as f from './functions.js'

// Fichero que contiene la clase World
export default class World {
  // Contructor por defecto que pasa los parámetros de filas y columnas
  // Crea un array de arrays
  // Y por cada array, crea una fila y recorre cada array creando una columna
  constructor(row = 10, col = 10) {
    this.row = row;
    this.col = col;
    this.size = this.row * this.col;
    this.map = Array(this.row);
    for (let i = 0; i < row; i++) this.map[i] = new Array(this.col).fill(0);

    this.map.forEach((element, i) => {
      var row = "<div class='row" + i + "' id='row'></div>";
      $('.table').append(row);
      element.forEach((element, j) => {
        var col = "<div class='col" + j + "' id='col'></div>";
        $('.row' + i).append(col);
      });
    });
  }

  // Método para crear Objetos de forma aleatoria
  // Resetea todos los obstáculos a 0, y de forma aleatoria si no había un objeto anteriormente, lo coloca
  // Si había uno vuelve a comprobar
  setRandObs(obs_percent = 0) {
    let obs_qty = this.size * obs_percent / 100;
    for (let i = 0; i < this.row; i++) {
      for (let j = 0; j < this.row; j++) {
        this.map[i][j] = 0;
        $('.row' + i + ' > .col' + j).css('background-color', 'white');
      }
    }

    for (let i = 0; i < obs_qty; i++) {
      let rand_row = f.getRandomInt(0, this.row);
      let rand_col = f.getRandomInt(0, this.col);

      if (this.map[rand_row][rand_col]) i--;
      else {
        this.map[rand_row][rand_col] = 1;
        $('.row' + rand_row + ' > .col' + rand_col).css('background-color', 'black');
      }
    }
  }

  // Elimina las filas y columnas
  clear() {
    if (this.ancho === undefined) this.ancho = 10;
    for (let i = 0; i < this.ancho; i++) {
      $('.row' + i).remove();
    }
  }
}
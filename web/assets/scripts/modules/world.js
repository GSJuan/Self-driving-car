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
    let i = 0;
    var html = '';
    while (i < this.row) {
      this.map[i] = new Array(this.col).fill(0);
      html += "<div class='row' id='row" + i + "'>";
      let j = 0;
      while (j < this.col) {
        html += "<div class='col' id='col" + j + "' style='border: 1px solid grey;'></div>";
        ++j;
      }
      html += "</div>";
      ++i;
    }
    $('.table').append(html);
  }

  // Método para crear Objetos de forma aleatoria
  // Resetea todos los obstáculos a 0, y de forma aleatoria si no había un objeto anteriormente, lo coloca
  // Si había uno vuelve a comprobar
  setRandObs(obs_percent = 0) {
    let obs_qty = this.size * obs_percent / 100;
    for (let i = 0; i < this.row; i++) {
      for (let j = 0; j < this.row; j++) {
        this.map[i][j] = 0;
        $('#row' + i + ' > #col' + j).css('background-color', 'white');
      }
    }

    for (let i = 0; i < obs_qty; i++) {
      let rand_row = f.getRandomInt(0, this.row);
      let rand_col = f.getRandomInt(0, this.col);

      if (this.map[rand_row][rand_col]) i--;
      else {
        this.map[rand_row][rand_col] = 1;
        $('#row' + rand_row + ' > #col' + rand_col).css('background-color', 'black');
      }
    }
  }

  // Elimina las filas y columnas
  clear() {
    if (this.row === undefined) this.row = 10;
    for (let i = 0; i < this.row; i++) 
      $('#row' + i).remove();
  }
}
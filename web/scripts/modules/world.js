export default class World {
  constructor(row = 10, col = 10) {
    this.row = row;
    this.col = col;
    this.size = this.row * this.col;
    this.map = Array(this.row);
    for (let i = 0; i < row; i++) this.map[i] = new Array(this.col).fill(0);
  }
  
  setRandObs(obs_percent = 0) {
    let obs_qty = this.size * obs_percent / 100;
    for (let i = 0; i < obs_qty; i++) {
      let rand_row = getRandomInt(0, this.row);
      let rand_col = getRandomInt(0, this.col);

      if (this.map[rand_row][rand_col]) i--;
      else {
        this.map[rand_row][rand_col] = 1;
        $('.row' + rand_row + ' > .col' + rand_col).css('background-color', 'black');
      }
    }
  }
}

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}
export default class World {
  constructor(row = 10, col = 10, obs_percent = 25, auto_obs = true) {
    this.row = row;
    this.col = col;
    this.size = this.row * this.col;
    this.map = Array(this.row);
    for (let i = 0; i < row; i++) this.map[i] = new Array(this.col).fill(0);

    let obs_qty = this.size * obs_percent / 100;
    if (auto_obs) {
      for (let i = 0; i < obs_qty; i++) {
        let rand_row = getRandomInt(0, row);
        let rand_col = getRandomInt(0, col);

        if (this.map[rand_row][rand_col]) i--;
        else this.map[rand_row][rand_col] = 1;
      }
    }
  }
}

function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min)) + min;
}
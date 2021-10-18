export function checkNaN(num) {
  if (Number.isNaN(parseInt(num))) return undefined;
  return parseInt(num);
}

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
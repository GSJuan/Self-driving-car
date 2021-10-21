// Fichero que contiene la clase Vehiculo
export default class Vehicle {
  // Constructor por defecto pasando su x e y, y lo implementa en la visualización
  // Primero copia los parámetros e incluye la imagen del vehículo en la fila x y columna y
  constructor(x = 0, y = 0, world) {
    if (world.map[y][x] == 0) {
      this.x = x;
      this.y = y;

      var img = '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 22 22" class="car" draggable="false"><path class="st0" d="m345.44 248.29l-194.29 194.28c-12.359 12.365-32.397 12.365-44.75 0-12.354-12.354-12.354-32.391 0-44.744l171.91-171.91-171.91-171.9c-12.354-12.359-12.354-32.394 0-44.748 12.354-12.359 32.391-12.359 44.75 0l194.29 194.28c6.177 6.18 9.262 14.271 9.262 22.366 0 8.099-3.091 16.196-9.267 22.373" transform="matrix(.03541-.00013.00013.03541 2.98 3.02)" fill="#000"/></svg>';
      
      let div = $('#row' + this.y + ' > #col' + this.x);
      let height = div.height();
      div.append(img);
      $('.row').css('height', height + 2 + 'px');
      console.log(height, $('.car').height(), div.height());
    }
  }

  // Crea el final de donde la clase Vehiculo debe llegar y lo visualiza
  // Primero copia los parámetros e incluye la imagen del final en la fila x_final y columna y_final
  setfinal(x = 0, y = 0, world) {
    if (world.map[y][x] == 0) {
      this.x_final = x;
      this.y_final = y;

      var img = '<svg xmlns:svg="http://www.w3.org/2000/svg" viewBox="-25 -25 150 150" xmlns="http://www.w3.org/2000/svg" version="1.0" width="100" height="100" class="final" draggable="false"><path class="st0" d="M 6.3895625,6.4195626 C 93.580437,93.610437 93.580437,93.610437 93.580437,93.610437" style="fill:none;fill-rule:evenodd;stroke:#000000;stroke-width:18.05195999;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1" id="path8986"/><path class="st1" d="M 6.3894001,93.6106 C 93.830213,6.4194003 93.830213,6.4194003 93.830213,6.4194003" style="fill:none;fill-rule:evenodd;stroke:#000000;stroke-width:17.80202103;stroke-linecap:butt;stroke-linejoin:miter;stroke-miterlimit:4;stroke-dasharray:none;stroke-opacity:1" id="path8988"/></svg>';

      let div = $('#row' + this.y_final + ' > #col' + this.x_final);
      let height = div.height();
      div.append(img);
      $('.row').css('height', height + 2 + 'px');
    }
  }

  // Remueve la visualización del vehiculo
  clear() {
    $('.car').remove();
  }

  // Remueve la visualización del final del vehiculo
  clearfinal() {
    $('.final').remove();
  }
}
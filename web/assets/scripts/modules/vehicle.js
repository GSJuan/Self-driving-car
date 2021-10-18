// Fichero que contiene la clase Vehiculo
export default class Vehicle {
  // Constructor por defecto pasando su x e y, y lo implementa en la visualización
  // Primero copia los parámetros e incluye la imagen del vehículo en la fila x y columna y
  constructor(x = 0, y = 0) {
    this.x = x;
    this.y = y;

    var img = "<img src='assets/img/car.svg' class='car'>";

    let div = $('.row' + this.y + ' > .col' + this.x);
    div.append(img);
    $('.car').css('height', div.css('height'));
    $('.car').css('width', div.css('width'));
  }

  // Crea el final de donde la clase Vehiculo debe llegar y lo visualiza
  // Primero copia los parámetros e incluye la imagen del final en la fila x_final y columna y_final
  setfinal(x, y) {
    this.x_final = x;
    this.y_final = y;

    var img = "<img src='assets/img/final.svg' class='final'>";

    let div = $('.row' + this.y_final + ' > .col' + this.x_final);
    div.append(img);
    $('.final').css('height', div.css('height'));
    $('.final').css('width', div.css('width'));
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
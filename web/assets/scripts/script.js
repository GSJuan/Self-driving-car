import World from './modules/world.js';
import Vehicle from './modules/vehicle.js';
import * as f from './modules/functions.js';
import './modules/jquery.js';

// Fichero donde está todo el funcionamiento de la interfaz
// Primero se importan los demas archivos JS y se declaran las variables globales

let alto = 0, ancho = 0;
let world = new World(ancho, alto);
let vehicle = new Vehicle(0, 0);

// Declara la creación de la clase World con el cambio de los inputs ancho y alto y comprueba si clickas en él
// Primero limpia world por si hay uno previo, luego obtiene los valores de alto y ancho y crea el mundo
// Por último crea una función asíncrona para checkear si clickas en el mundo y nunca termina
$('#alto, #ancho').on("change", () => {
  world.clear();

  alto = f.checkNaN($('#alto').val());
  ancho = f.checkNaN($('#ancho').val());

  world = new World(ancho, alto);

  setInterval(f.checkclickworld(world), 10);
})

// Controla los cambios del input del % de obstaculos y llama al método del mundo
$('#obstaculos_input').on("change", () => {
  let obstaculos = f.checkNaN($('#obstaculos_input').val());
  world.setRandObs(obstaculos);
})

// Controla los cambios del input de la posicion del vehiculo y crea el objeto vehiculo
$('#x_vehiculo, #y_vehiculo').on("change", () => {
  vehicle.clear();

  let x = f.checkNaN($('#x_vehiculo').val());
  let y = f.checkNaN($('#y_vehiculo').val());

  vehicle = new Vehicle(x, y);
})

// Controla los cambios del input del destino final y los introduce en el método de vehiculo
$('#x_final, #y_final').on("change", () => {
  vehicle.clearfinal();

  let x = f.checkNaN($('#x_final').val());
  let y = f.checkNaN($('#y_final').val());

  vehicle.setfinal(x, y);
})

$('#grid').on("change", () => {
  if ($('#grid').is(":checked"))
    $('.table #col').css('border', '1px solid grey');
  else 
    $('.table #col').css('border', '0px solid grey');
})
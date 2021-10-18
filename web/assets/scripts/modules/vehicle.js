export default class Vehicle {
  constructor(x = 0, y = 0) {
    this.x = x;
    this.y = y;

    var img = "<img src='assets/img/car.svg' class='car'>";

		let div = $('.row' + this.y + ' > .col' + this.x);
		div.append(img);
		$('.car').css('height', div.css('height'));
		$('.car').css('width', div.css('width'));
  }

	setfinal(x, y) {
		this.x_final = x;
		this.y_final = y;
		
		var img = "<img src='assets/img/final.svg' class='final'>";

		let div = $('.row' + this.y_final + ' > .col' + this.x_final);
		div.append(img);
		$('.final').css('height', div.css('height'));
		$('.final').css('width', div.css('width'));
	}

	clear() {
		$('.car').remove();
	}

	clearfinal() {
		$('.final').remove();
	}
}
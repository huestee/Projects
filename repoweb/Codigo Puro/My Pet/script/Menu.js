
var Menu = document.getElementById('ConteMenu');
var Nav = document.getElementById('Mcolor');

/*Para calcular la distancia de la pigana hasta donde esta el menu:
alert(Menu.offsetTop);		*/

var H = Menu.offsetTop;
/*	Para calcular la distancia que hay de l pagina hasta el menu cuando se hace scroll
alert(window.pageYOffset);		*/

	window.addEventListener('scroll', function(){
		'use strict';
		if (window.pageYOffset > H) {
			/*----------------------------------Menu Html------------------------------------*/
			Menu.classList.add('MenuFixed');	  /*Para agregarle al menu los estilos de 												MenuFixed*/
			Menu.style.background = "#fff"; 	/*Para agregarle un color de fondo*/
			$(".H1").css('color','#000');	/*Para agregarle un color de texto*/
			
			/*------------------------------------Nav Html------------------------------------*/
			Nav.style.background = "rgba(255,255,255,0.6)"; /*Para agregarle un color de fondo al 
															menu */
			Nav.style.boxShadow = "3px 3px 4px rgba(0,0,0,0.4)"; /*Para agregar una sombra al  														menu */
			$(".A").css('color','#000'); /*Para ajustar el color de la letra*/
			
			$(".A").addClass('Borde2');			/*Borde*/
			$(".A").removeClass('Borde1');		/*Borde*/
			
			/*Para cambiar efecto del hover a la clase .A*/
			$(".A").hover(function(){
    			$(this).css("background-color", "rgba(0,0,0,0.5)");
    			$(this).css("color", "#fff");
			}, function(){
    			$(this).css("background-color", "transparent");
				$(this).css("color", "#000");
    		});  
		}
		else{
			/*----------------------------------Menu Html------------------------------------*/
			Menu.classList.remove('MenuFixed');	/*Para quitarle al menu los estilos de 											MenuFixed*/
			Menu.style.background = "#333";
			$(".H1").css('color','#fff');
			
			/*------------------------------------Nav Html------------------------------------*/
			Nav.style.background = "rgba(0,0,0,0.5)";
			Nav.style.boxShadow = "none";
			$(".A").css('color','#fff');
			
			$(".A").removeClass('Borde2');
			$(".A").addClass('Borde1');
			
			/*Para cambiar efecto del hover a la clase .A*/
			$(".A").hover(function(){
    			$(this).css("background-color", "rgba(255,255,255,0.5)");
				$(this).css("color", "#000");
			}, function(){
    			$(this).css("background-color", "transparent");
    			$(this).css("color", "#fff");
    		}); 
		}
	});
	

/*$(".MenuFixed").css('background','#fff');*/
/*
		if (window.pageYOffset < H) {
			$(".MenuFixed").css('background','#333');
		}*/
		
/*
$(document).ready(function () {
	'use strict';
    window.scroll(function () {
        var y = $(this).scrollTop();
        var quienes = $('#ConteMenu').offset().top;
		var nuestros = $('#nuestros_trabajos').offset().top;
		var contacto = $('#contacto').offset().top;

		var quienes = quienes - 200;
		var nuestros = nuestros - 200;
		var contacto = contacto - 200;
 
        if (y >= H) {
            $('ConteMenu').css('background-color','rgba(0,0,0,1');
        }
        
        if (y >= nuestros) {
            $('header').css('background-color','rgba(243, 156, 18,0.8');
        }
        
        if (y >= contacto) {
            $('header').css('background-color','rgba(192, 57, 43,0.8');
        }
    });
});*/
// JavaScript Document

console.log('Correcto');
//__QuerySelector, selecciona cualquier objeto de nuestro HTML__
//__addEventListener, detecta un evento__
document.querySelector('#btn').addEventListener('click', traerDatos);

//__Funcion Traer Datos__
function traerDatos(){
	'use strict';
	console.log('Funcion Activada');
	
	var xhttp=new XMLHttpRequest();
	
	//__Solicitud reciba una respuesta__
	xhttp.onreadystatechange=function(){
		//console.log('Dentro onready');
		if(this.readyState==4 && this.status==200){
			//console.log(this.responseText);
			
			//__Extrae la infornacion del json__
			let obj=JSON.parse(this.responseText);
			//console.log(obj);
			var table='';
			
			//__Acceder a los datos del json__
			for(var i=0; i<obj.length; i++){
				//console.log(obj[i].name);				
				table+='<tr><td>'+
					obj[i].name+'</td><td>'+
					obj[i].category+'</td><td>'+
					obj[i].salary+'</td><td>'+
					(i+1)+'</td></tr>';
			}
			//console.log(table);
			document.getElementById('res').innerHTML=table;
		}
	};
	
	//__Envia solicitud al servidor__
	xhttp.open('GET', 'json/array.json', true);
	//xhttp.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
	xhttp.send();
}
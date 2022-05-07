#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
using namespace std;
class estudiante
{

	  public:	string car, nom, ape, dir, gen, em, fech;  int tel;  
	  string carnet = car;
	  string nombre = nom;
	  string apellido = ape;
	  string direccion = dir;
	  string genero = gen;
	  string email = em;
	  string fecha_nacimiento = fech;
	  int telefono = tel;


	  void setNit(string car) { carnet = car; }
	  void setNombres(string nom) { nombre = nom; }
	  void setDireccion(string ape) { apellido = ape; }
	  void setDireccion(string dir) { direccion = dir; }
	  void setNit(string gen) { genero = gen; }
	  void setNombres(string em) { email = em; }
	  void setNit(string fech) { fecha_nacimiento = fech; }
	  void setTelefono(int tel) { telefono = tel; }

	  string getNit() { return carnet; }
	  string getNombres() { return nombre; }
	  string getDireccion() { return apellido; }
	  string getDireccion() { return direccion; }
	  string getNit() { return genero; }
	  string getNombres() { return email; }
	  string getNit() { return fecha_nacimiento; }
	  int getTelefono() { return telefono; }


	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string t = to_string(telefono);
		  if (cn.getConectar()) {
			  string  insertar = "INSERT INTO estudiante(carnet,nombre,apellido,direccion,genero,email,fecha_nacimiento,telefono) VALUES ('" + carnet + "','" + nombre + "','" + apellido + "','" + direccion + "','" + genero + "','" + email + "','" + fecha_nacimiento + "'," + t + ")";
			  const char* i = insertar.c_str();

			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "Ingreso Exitoso ..." << endl;
			  }
			  else {
				  cout << " xxx Error al Ingresar  xxx" << endl;
			  }
		  }
		  else {
			  cout << " xxx Error en la Conexion xxxx" << endl;
		  }
		  cn.cerrar_conexion();
	  }
	  void leer() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();

		  if (cn.getConectar()) {

			  cout << "------------ Datos del Estudiante ------------" << endl;
			  string consulta = "SELECT * FROM db_estudiante.estudiantes";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << endl;
				  }

			  }
			  else {
				  cout << " xxx Error al Consultar  xxx" << endl;
			  }

		  }
		  else {
			  cout << " xxx Error en la Conexion xxxx" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  void actualizar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();

		  cn.abrir_conexion();
		  string id = to_string(id_estudiante);
		  if (cn.getConectar()) {

			  string update = "UPDATE `db_estudiante`.`estudiantes` SET `id_estudiante` = '', `carnet` = '', `nombre` = '', `apellido` = '', `direccion` = '', `genero` = '', `email` = '', `fecha_nacimiento` = '', `telefono` = '' WHERE (`id_estudiante` = '1')";

			  const char* i = update.c_str();

			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << "INGRESADO CON EXITO .... \n";

			  }
			  else {
				  cout << "ERROR DE CONECCION.... \n";
			  }
		  }
		  else {
			  cout << "ERROR DE CONECCION.... \n";
		  }
		  cn.cerrar_conexion();
	  }

	  void eliminar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila = 0;
		  MYSQL_RES* resultado = 0;

		  cn.abrir_conexion();
		  string id = to_string(id_estudiante);
		  if (cn.getConectar()) {

			  string delite = "DELETE FROM `db_estudiante`.`estudiante` WHERE (`id_estudiante` = ' ')";

			  const char* i = delite.c_str();

			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {

				  cout << "ELIMINADO CON EXITO .... \n";

			  }
			  else {
				  cout << "ERROR DE CONECCION.... \n";
			  }
		  }
		  else {
			  cout << "ERROR DE CONECCION.... \n";
		  }
		  cn.cerrar_conexion();
	  }
};


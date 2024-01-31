IPA - Idiomas para aprender

Al descomprimir el proyecto se verán tres carpetas:

Debug -> archivos objeto y ejecutable de aplicacion
src -> contiene las cabeceras y archivos fuente
doc -> contiene archivos .txt (libros, palabras para juegos y estadisticas)

"palabras-1.txt": archivo de catedra con palabras utilizadas para los juegos

"usuarios.bin": archivo binario con 100 usuarios precargados(VER INFO_USUARIOS.TXT EN DIRECTORIO PRINCIPAL PARA POSIBLES LOG-INS)

    doc/estadisticas -> directorio contendrá archivos estadiscticos generados por
			el procesador de texto
	
	"(nombrelibro)/frecuencias.txt" contienen tabla de dos columnas caracter - apariciones
					donde se contabilizan las apariciones de cada 'caracter'
					(no solo letras) del libro

	"(nombrelibro)/palabraX.txt": 	contiene registro de todas las palabras del libro que comienzan
				     	por 'X', una por renglon, y a su derecha las apariciones encontradas
					en el libro

    doc/libros -> directorio contiene los archivos libro que la catedra proporcionó


CONSIDERACIONES PARA SOLUCIONES DE PROCESADOR DE TEXTO

    - Investigando sobre la impresion de caracteres en al consola de windows se decidió que era 
      conveniente trabajar bajo la codepage 1252 (ANSI - Latin)

    - En la cuenta de frecuencia de caracteres se cuentan todos los caracteres, inclusive los que no
      son letras (como saltos de linea, espacios, y tabulados).

    - El estudio de frecuencia de caracteres permitió determinar que ninguna palabra de los dos libros
      comenzaba con 'ä', 'ö' ni ningun otro caracter acentuado, por lo que la matriz de estadisticas a
      nivel de palabras solo considera palabras que comienzan con letras italianas no acentuadas

    - La lista enlazada se realizo separando palabras como l'olio en dos, 'l' que se abrevia de 'il', y
      "olio" que por si misma es una palabra,


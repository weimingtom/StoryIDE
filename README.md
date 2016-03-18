# Story IDE

*Entono de Desarrollo Integrado* simple orientado a crear y probar
aventuras conversacionales escrita en **stry**.  

![Modo editor]](/pics/StoryIDE_Editor.png)
## Características

- Resaltadode sintaxis
- Hipervínculos a declaraciones de escena dinámicos
- Intérprete y debugger
- Comenzar directamente en una escena (en modo juego)

___
## Lenguaje **.stry**
Permite definir una jerarquía de textos (**escenas**) que serán mostrados al usuario así como opciones para desplazarse por dicha estructura.

La idea es la de poder crear una historia en la cual el usuario pueda
tomar decisiones que condicionen su transcurso, pudiendo existir varios finales, varias formas de llegar a un mismo final, situaciones cíclicas etc. Este sistema, de forma general, permite representar cualquier algoritmo en el que se nos guíe por sus pasos y se nos pregunte información en determinados casos, sin embargo, continuaremos con la visión de historia al estilo *elige tu propia aventura* para explicar el funcionamiento del leguaje.  
Se distinguen tres conceptos básicos:

### Escenas:  

Contienen el texto que será mostrado al usuario en un momento dado de
la historia. Por ejemplo, una primera escena podría ser algo como:

> Bienvenido a StoryIDE, comencemos con la explicación

Cada escena tiene un identificador numérico único asociado (**etiqueta**), y siempre
debe existir la escena inicial, la 0. La manera de definirlas es mediante la sintaxis `<etiqueta> Texto de la escena`

Para el caso de la escena anterior, tratándose de la primera, quedaría de la forma


    <0> Bienvenido a StoryIDE, comencemos con la explicación

Podemos definir varias escenas sin importar los saltos de línea, tabuladores etc. Además no es necesario seguir ningún orden.

    <0> Esta es una
    escena inicial          con muchas cosas raras
    pero no pasa nada

    <1> Esta es otra escena (con etiqueta 1) a la que no le afectan
    las cosas raras de la escena 0

    <193> Esta es una escena con un número de etiqueta muy grande
    y no hay problema por que no existan ni la 2, ni la 3, ni la 4 etc.



### Saltos:

Tras esto, seguramente querremos poder avanzar de un punto a otro de la historia, por lo que emplearemos los saltos. Un salto es la indicación
de que cual es la siguiente escena que se va a mostrar tras la actual y se define con la sintaxis `@etiqueta`.

Por ejemplo si quisiésemos que de la escena 0 de presentación de antes se pasara a otra escena distinta, deberemos escribir

    <0> Bienvenido a StoryIDE, comencemos con la explicación @1

    <1> Ya casi hemos terminado

Esto nos mostrará como resultado:

> Bienvenido a StoryIDE, comencemos con la explicación  
  Ya casi hemos terminado

### Opciones.

Si nos fijamos, para el caso anterior, de una escena se salta a la otra sin más, mostrando todo el texto de una sola vez. Esto es así porque
no hay nada que le indique lo contrario, si queremos que el usuario pueda tomar decisiones sobre a qué escena moverse debemos definir opciones.  
Las opciones están constituidas por dos elementos: un texto descriptivo de la opción y un salto de a qué escena lleva este camino; su sintaxis es
`~ Texto descriptivo de la opción @etiqueta`.  

Podemos declarar todas las opciones que queramos en cualquier orden, ya que es el intérprete el encargado de asociar un número de opción
a cada una, nosotros solo debemos preocuparnos de que esta comience por ~.

Continuando con el ejemplo anterior, veamos como queda todo en conjunto

      <0> Bienvenido a StoryIDE, comencemos con la explicación @1

      <1> Ya casi hemos terminado @2

      <2> ¡Felicidades! Has llegado al final. ¿Te ha gustado?
          ~ Sí, mucho @3
          ~ No, nada @4

      <3> Me alegro de que te guste

      <4> Eres un perro sarnoso, filibustero, marinero de agua dulce, bebe sin sed,
      lorito, antropófago, bochi-bozuc, coloquíntido...

Por lo que al probarlo se mostrará

> Bienvenido a StoryIDE, comencemos con la explicación  
  Ya casi hemos terminado  
  ¡Felicidades! Has llegado al final. ¿Te ha gustado?

> 1.- Sí, mucho  
  2.- No, nada

  - Si elegimos la opción 1, mostrará

  >Me alegro de que te guste

  - Si elegimos la opción 2, [habremos hecho enfadar mucho a alguien](http://es.tintin.wikia.com/wiki/Los_insultos_del_capit%C3%A1n_Archibaldo_Haddock)

## Otros aspectos

#### Comentarios
Comentarios de línea tipo C++/Java. Lo escrito tras `//` es omitdo.

    <0> Nunca hagas enfadar al capitán haddock //Esto es un comentario que pongo para explicar o anotar algo      

da como resultado únicamente

>Nunca hagas enfadar al capitán haddock

#### Título
Obligatorio para poder probar la historia, se define como
`{ Título de la historia }`

#### Autor
Obligatorio para poder probar la historia, se define como
`# Autor de la historia #`

#### Bucles
Por razones obvias,**no** o se permiten declaraciones del tipo

    <0> Esto solo sirve para fastidiar @1
    <1> Y yo no lo voy a permitir @0

En las que las escenas saltan entre sí infinitamente.  
Esto no se aplica cuando hay opciones en el bucle, y **sí** se puede hacer:

    <0> ¿Tú lo que quieres es molestar no?
    ~ Si @0
    ~ Si y mucho @0

___

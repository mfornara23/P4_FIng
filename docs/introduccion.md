### Introducción

En primer lugar se desea que se registren los usuarios. De éstos se conoce su nombre, su email (el cual
lo identifica), una imagen del perfil (de la cual se almacenará su url) y una contraseña para habilitar el
ingreso a la aplicación. El email y su contraseña le permitirán iniciar sesión en el sistema.
Los usuarios del sistema pueden ser docentes o estudiantes. De los docentes interesa saber el nombre
del instituto al que pertenecen y si están asignados a práctico, teórico o monitoreo (en esta primera
versión, sólo a uno de ellos), para cada asignatura a la cual fueron asignados. De los estudiantes
interesa además registrar su cédula de identidad (que también lo identifica) y conocer el conjunto de
asignaturas que él/ella está cursando.

De cada asignatura se conoce el código que la identifica y su nombre. Además se sabe que todas las
asignaturas tienen al menos un docente asignado para su dictado.

Los docentes pueden iniciar una clase de una asignatura ingresando el nombre que desean asignarle
(Ej: P4 - Práctico 3) y si es un teórico, práctico o monitoreo. El docente que inicia la clase debe estar
asignado a la asignatura correspondiente. Al darse de alta la clase se le asignará automáticamente un
número que la identifica y la fecha y hora de comienzo. De las clases de teórico interesa además
conocer la cantidad de asistentes. Cualquier docente puede unirse a una clase siempre y cuando esté
asignado a la asignatura correspondiente y su asignación (teórico, práctico o monitoreo) coincida con
el tipo de clase.

En caso de iniciar una clase de monitoreo se deberá agregar la lista de estudiantes habilitados para
asistir al mismo, que no serán más de 15 y siempre debe haber al menos un estudiante. Los
estudiantes habilitados deben estar cursando la asignatura correspondiente. Si la asignatura tiene
clases de monitoreo, los estudiantes que la cursan deben estar habilitados para asistir en al menos una
de dichas clases.

Los estudiantes pueden asistir a una clase en vivo, para lo cual deben estar cursando la asignatura en
cuestión, o pueden reproducirla luego de finalizada tantas veces como así lo deseen. En ambos casos
se deberá guardar la fecha y hora del comienzo y fin de la asistencia a una clase a los efectos de luego
generar estadísticas de acceso y utilización de los recursos.
Los usuarios pueden enviar mensajes de texto o responder a uno mientras participan de una clase,
estableciendo de esta forma conversaciones. Se debe registrar para cada mensaje la fecha y hora en la
que fue enviado y en caso de ser una respuesta a otro mensaje interesa saber en respuesta a cual. El
sistema genera de forma automática un identificador numérico para cada mensaje enviado.
Una vez finalizada la clase se deberá guardar la url del video generado para su reproducción posterior,
así como las fecha y hora de fin de la clase.
En los casos que se requiere registrar la fecha y hora se debe considerar la misma con precisión de
segundos.

Por otra parte, se deberá agregar la funcionalidad para que los usuarios puedan suscribirse para recibir notificaciones por email cada vez 
que se envía algún mensaje nuevo y de acuerdo a un modo de suscripción seleccionado. Será posible 
enviar mensajes en cualquier clase, sea esta en vivo o no. 

Inicialmente existirán tres modos de suscripción, pero a futuro se debe prever la incorporación de 
nuevos modos. Inicialmente, los modos de suscripción posibles para recibir notificaciones son: 

- Cada vez que se envía un mensaje nuevo en cualquier asignatura en la que el usuario tenga 
relación (es docente de la asignatura o es un estudiante inscripto).
 
- Cada vez que se crea un mensaje en cualquier clase a la que el estudiante asiste y/o reproduce; 
y para los docente si la inicia y/o se une a la misma. 

- Cada vez que se crea un mensaje que es respuesta a un mensaje del usuario. 
En cualquier momento los usuarios podrán consultar su lista de notificaciones, cancelar la suscripción 
o cambiar el modo.
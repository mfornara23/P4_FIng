# Casos de uso

### 1. Alta de usuario - Administrador
El caso de uso comienza cuando un administrador desea agregar usuarios en el sistema. Para cada usuario, sea docente o estudiante, el sistema pide su nombre, email, contraseña y url de la imagen. Si el usuario es docente, el sistema adicionalmente pide el nombre del instituto al que pertenece. Si el usuario es estudiante se pide el documento de identidad. Luego se da la opción de confirmar o cancelar, en caso de confirmar se dade alta el usuario con los datos ingresados. Finalmente, el sistema pregunta si desea seguir agregando usuarios o terminar el casode uso 


### 2. Alta de asignatura - Administrador
El caso de uso comienza cuando un administrador desea agregar una nueva asignaturaen el sistema. Para cada asignatura el sistema pide su nombre y código. Además, pide indicar si la asignatura tiene o no instancias de teórico, práctico y monitoreo. Luego el sistema muestra los datos ingresados y da la opción de confirmar o cancelar. En caso de confirmar se da de alta en el sistema una nueva asignatura con la información ingresada, de lo contrario termina el caso de uso.


### 3. Asignación de docentes a una asignatura . Administrador
El caso de uso comienza cuando un administrador, desea asignar docentes a una asignatura en el sistema. Para ello el sistema lista todas las asignaturas registradas y el administrador selecciona una de ellas. A continuación, se listan los docentes registrados en el sistema que todavía no han sido asignados a dicha asignatura y el administrador selecciona uno, junto con su rol de dictado (teórico, práctico o monitoreo). Luego, el administrador debe o bien confirmar la asignación o bien cancelarla. Finalmente, el sistema pregunta si desea seguir agregando docentes a la asignatura seleccionada o terminar el caso de uso.


### 4. Inscripción a las asignaturas - Estudiante
El caso de uso comienza cuando un estudiante desea inscribirse a una o varias asignaturas. Para ello el sistema lista todas las asignaturas a las cuales el estudiante todavía no está inscripto y éste selecciona una de ellas. Luego el estudiante debe o bien confirmar la inscripción o bien cancelarla. Este comportamiento se repite mientras elestudiante quiera seguir inscribiéndose a otras asignaturas.


### 5. Inicio de clase - Docente
El caso de uso comienza cuando un docente desea iniciar una clase en el sistema. Para ello el sistema lista todas las asignaturas a las cuales el docente está asignado y éste selecciona una de ellas. A continuación, el sistema solicita el nombre de la clase yla fecha y hora de comienzo. En el caso de que el docente tenga asignación de monitoreo para la asignatura seleccionada, se debe ingresar la lista de habilitados. Para ello el sistema lista todos los estudiantes inscriptos a la asignatura y el docente selecciona uno de ellos. Este comportamiento se repite mientras el docente quiera seguir agregando estudiantes a la lista de habilitados. Luego el sistema muestra los datos ingresados y el id generado para la clase, brindandola opción de confirmar o cancelar. En caso de confirmar se da de alta en el sistema una nueva clase con los datos ingresados, de lo contrario termina el caso de uso.


### 6. Finalización de clase - Docente
El caso de uso comienza cuando un docente desea finalizar una clase en el sistema. Para ello el sistema lista todas las clases en vivo iniciadas por el docente y que aún no han finalizado, y éste selecciona una de ellas. Luego el sistema muestra los datos de la clase (id, nombre, tipo y fecha y hora de inicio) y da la opción de confirmar o cancelar. En caso de confirmar, el sistema toma su fecha y hora para registrar la finalización de la clase, y genera una url para el video. En caso de ser un teórico se calcula la cantidad de asistentes a la misma. Para cada estudiante que está asistiendo en vivo al momento de finalizar la clase, se debe marcar la fecha y hora de fin de la asistencia, que será aquella de finalización de la clase.


### 7. Envío de mensaje - Usuario
El caso de uso comienza cuando un usuario desea enviar un mensaje. Para ello el sistema lista las clases en vivo en las cuales el usuario está participando y éste selecciona una de ellas. A continuación, el sistema lista todos los mensajes existentes para la clase seleccionada, indicando cuando son respuesta a otro mensaje. Luego el sistema pregunta si el mensaje a enviar es en respuesta a uno ya existente. En caso afirmativo, el usuario selecciona uno. Luego el sistema solicita que se ingrese el texto del mensaje a enviar y da la opción de confirmar o cancelar. En caso de confirmar se da de alta en el sistema el mensaje con los datos ingresados, de lo contrario termina el caso de uso.


### 8. Asistencia a clase en vivo - Estudiante
El caso de uso comienza cuando un estudiante desea asistir a una clase en vivo. Para ello el sistema lista las asignaturas que está cursando y el estudiante selecciona una de ellas. A continuación, se listan las clases disponibles de esa asignatura en el sistema a las que puede asistir en vivo y el estudiante selecciona una. Luego el sistema muestra los datos ingresados y da la opción de confirmar o cancelar. En caso de confirmar se registra en el sistema la asistencia con la información ingresada y fecha y hora de inicio correspondiente a la del sistema, de lo contrario termina el caso de uso.


### 9. Reproducción de clase en diferido - Estudiante
El caso de uso comienza cuando un estudiante desea asistir a una clase en diferido. Para ello el sistema lista las asignaturas que está cursando y el estudiante selecciona una de ellas. A continuación, se listan las clases disponibles de esa asignatura en el sistema a las que puede reproducir en diferido y el estudiante selecciona una. Luego el sistema muestra los datos ingresados y da la opción de confirmar o cancelar. En caso de confirmar, se registra en el sistema la reproducción con la información ingresada y fecha y hora de inicio correspondiente a la del sistema, de lo contrario termina el caso de uso. Finalmente, el sistema devuelve todos los mensajes intercambiados durante la clase, con sus respectivas respuestas.


### 10. Listado de clases - Docente 
El caso de uso comienza cuando un docente desea consultar en el sistema la información de sus clases. Para ello el sistema lista las asignaturas en las que el docente participa y éste selecciona una de ellas. El sistema listará toda la información básica de las clases y los nombres de los docentes que las dictaron. Además, en caso de ser un Teórico se debe mostrar la cantidad de asistentes, y si es un Monitoreo se debe listar el nombre de los estudiantes asistentes al mismo.


### 11. Tiempo de dictado de clases - Administrador
El caso de uso comienza cuando el administrador del sistema desea saber el tiempo total de dictado de las clases por asignatura. Se entiende por tiempo de dictado de una clase el tiempo transcurrido entre su inicio y fin. Se debe mostrar para cada asignatura la suma de los tiempos de dictado de todas sus clases.


### 12. Tiempo de asistencia a clase - Docente
El caso de uso comienza cuando un docente desea saber el tiempo promedio de asistencias de los estudiantes a las clases que dictó. Se entiende por tiempo de asistencia de un estudiante a una clase, el tiempo transcurrido entre el inicio y fin de una asistencia en vivo. Inicialmente el sistema lista las asignaturas en las que el docente participa y éste selecciona una de ellas. Se debe mostrar para cada clase que el docente dictó, el promedio de los tiempos de asistencia (calculado sobre los estudiantes que asistieron).


### 13. Eliminación de asignatura - Administrador
El caso de uso comienza cuando el administrador del sistema desea eliminar una asignatura del sistema. Para ello el sistema muestra información de todas las asignaturas, el administrador selecciona por su identificador una de ellas y se da la opción de confirmar o cancelar. En caso de confirmar, se elimina esa asignatura junto con todas sus clases, las asistencias y participaciones (mensajes) en cada una de ellas.


### 14. Finalización de asistencia a clase en vivo
El caso de uso comienza cuando un estudiante desea finalizar la asistencia a una clase en vivo. Para ello el sistema lista las clases a las que está asistiendo en vivo. Luego el estudiante selecciona una clase y el sistema da la opción de confirmar o cancelar. En caso de confirmar se finaliza la asistencia registrándose la hora de finalización, de lo contrario termina el caso de uso.


### 15. Consulta de notificaciones
El caso de uso comienza cuando un usuario desea consultar las notificaciones recibidas. Para ello el usuario le indica al sistema que desea realizar la consulta y el sistema lista todas las notificaciones del usuario. Al terminar la consulta el sistema eliminará las notificaciones del usuario.


### 16. Suscribirse a notificaciones
El caso de uso comienza cuando un usuario desea suscribirse para recibir notificaciones. Para ello el usuario le indica al sistema el modo de suscripción


### 17. Eliminar suscripción
El usuario le indica al sistema que desea eliminar su suscripción.


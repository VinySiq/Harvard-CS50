# TIMEU Schedule
#### Video Demo:  https://youtu.be/yMtO4LCz1CQ
#### Description:

TimeU is a schedule that you can use to organizate your daily works.

# Features:
Was develop using:
 - HTML;
 - CSS;
 - JavaScript and the DOM;
 - Canva;
 - Bootstrap.

I used the DOM to manipulate the notes and make my logical for their appear or not.

I made the objects design on Canva.

# Introduction
I started my web page creating a HTML page using the default HTML:5 code.
On index.html bootstrap was fundamental to make the styles and the basics scripts.

I started making the navbar and integrating its to my necessities, using the image that I created on canva
to be my favicon.

CSS was my second challenge in this project, I need to learn new things about it to make my project batter than was.

JavaScript script was the harder thing that I've made, I need to learn DOM and I take the sticky notes maded on my html and css and integrated it on my script.js. This is my script.js:

            let random_margin = ["-5px", "1px", "5px", "10px", "7px"];
            let random_colors = ["#c2ff3d","#ff3de8","#3dc2ff","#04e022","#bc83e6","#ebb328"];
            let random_degree = ["rotate(3deg)", "rotate(1deg)", "rotate(-1deg)", "rotate(-3deg)", "rotate(-5deg)", "rotate(-8deg)"];
            let index = 0;

            window.onload = document.querySelector("#user_input").select();

            document.querySelector("#add_note").addEventListener("click", () => {
            document.querySelector("#modal").style.display = "block";
            });

            document.querySelector("#hide").addEventListener("click", () => {
            document.querySelector("#modal").style.display = "none";
            });

            document.querySelector("#user_input").addEventListener('keydown', (event) => {
            if(event.key === 'Enter'){
                const text = document.querySelector("#user_input");
                createStickyNote(text.value);
            }
            });

            createStickyNote = (text) => {
            let note = document.createElement("div");
            let details = document.createElement("div");
            let noteText = document.createElement("h1");

            note.className = "note";
            details.className = "details";
            noteText.textContent = text;

            details.appendChild(noteText);
            note.appendChild(details);

            if(index > random_colors.length - 1)
                index = 0;

            note.setAttribute("style", `margin:${random_margin[Math.floor(Math.random() * random_margin.length)]}; background-color:${random_colors[index++]}; transform:${random_degree[Math.floor(Math.random() * random_degree.length)]}`);

            note.addEventListener("dblclick", () => {
                note.remove();
            })

            document.querySelector("#all_notes").appendChild(note);
            }

# Documentation
 - https://www.javascripttutorial.net/javascript-dom/
 - https://pt.khanacademy.org/computing/computer-programming/html-css-js/js-and-the-dom/pt/the-dom-document-object-model
 - https://stackoverflow.com/

# About CS50
CS50 is a openware course from Havard University and taught by David J. Malan

Introduction to the intellectual enterprises of computer science and the art of programming. This course teaches students
how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures,
encapsulation, resource management, security, and software engineering. Languages include C, Python, and SQL plus
students’ choice of: HTML, CSS, and JavaScript (for web development).

CS50 helps me a lot in my career transition, so I'm so happy to finish this course.

Thank you for all CS50.

This was my project on CS50: Introduction to Computer Science.
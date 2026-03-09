# Local Chat (C++)

Local Chat is a simple chat application written in C++.
The program allows users to send and store messages locally using a file-based system.

The chat history is saved in a file, so messages remain available even after the program is closed and reopened.

This project includes two versions:

* Qt GUI version
* Console version

## Features

* Send messages locally
* Persistent chat history stored in a file
* Two versions of the application:

  * Qt graphical interface
  * Console-based interface
* Username support
* Built-in commands

## Commands

The following commands are available in the chat:

| Command    | Description                           |
| ---------- | ------------------------------------- |
| `/help`    | Displays all available commands       |
| `/clear`   | Clears the chat history               |
| `/newName` | Changes the username                  |
| `/exit`    | Exits the chat (console version only) |

## Chat History

All messages are stored in a file.
When the application is closed and opened again, the previous chat history is automatically loaded.

## Versions

### Console Version

* Runs entirely in the terminal
* Supports all commands including `/exit`
* Lightweight and simple to run

### Qt Version

* Graphical user interface built with Qt
* Provides a more user-friendly chat experience

## Project Structure

```id="e8zv1r"
.
├── console/        # Console version of the chat
├── qt/             # Qt GUI version
├── chat_history.txt
├── slides/         # Project presentation
└── README.md
```

## How It Works

1. The program reads the chat history file when it starts.
2. Users can send messages or execute commands.
3. Each new message is written to the chat file.
4. The history remains saved between sessions.

## Presentation

A presentation explaining the project design and functionality is included in the repository slides.

## Technologies Used

* C++
* File I/O
* Qt (for the GUI version)

## Author

Edmond Vardanyan
Student at Synopsys Education Department

## License

This project is for educational and learning purposes.

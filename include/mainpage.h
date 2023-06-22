/*! \mainpage JSON Parser Console Application Documentation
 *
 * \section intro_sec Introduction
 *
 * Welcome to the documentation of our JSON Parser Console Application.
 * This application is designed to parse, manipulate and validate JSON files.
 * It provides a console-based interface for working with JSON data.
 * You can open, save, and perform various operations on JSON data like search,
 * insert, delete, and move JSON elements.
 *
 * \section usage_sec Usage
 *
 * After you open a JSON file with our application, you can use the following commands:
 *
 * - `validate`: Validates the JSON file.
 * - `print`: Prints the JSON file.
 * - `search <key>`: Searches for the key in the JSON and returns its path.
 * - `contains <value>`: Checks if the JSON contains the provided value.
 * - `set <path> <new_value>`: Sets the new value at the given path.
 * - `create <path> <value>`: Creates a new element with the given value at the specified path.
 * - `delete <path>`: Deletes the element at the given path.
 * - `move <fromPath> <toPath>`: Moves the element from the source path to the destination path.
 * - `save` [<path>] saveas <file> [<path>]: Saves the JSON file to the specified path.
 *
 * \section classes_sec Classes
 *
 * The application includes several classes to handle JSON data, including:
 *
 * - `JsonManager`: Manages JSON file operations like opening, saving, etc.
 * - `JsonParser`: Parses JSON data.
 * - `JsonObject`, `JsonArray`, `JsonValue`: Represent different types of JSON elements.
 * - `JsonKey`: Represents a key in a JSON object.
 * - `JsonValidator`: Validates a JSON string.
 * - `JsonException` and its subclasses: Represent various exceptions that can occur while handling JSON data.
 *
 * Detailed information about these classes can be found in the "Classes" section.
 *
 * \section install_sec Installation
 *
 * To use the JSON Parser Console Application, simply clone the repository and build it using a C++ compiler.
 * The application does not have any external dependencies.
 *
 */

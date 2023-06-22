<h1>JSON Parser Console Application Documentation </h1>
<div class="contents">
<div class="textblock"><h1><a class="anchor" id="intro_sec"></a>
Introduction</h1>
<p>Welcome to the documentation of our JSON Parser Console Application. This application is designed to parse, manipulate and validate JSON files. It provides a console-based interface for working with JSON data. You can open, save, and perform various operations on JSON data like search, insert, delete, and move JSON elements.</p>
<h1><a class="anchor" id="usage_sec"></a>
Usage</h1>
<p>After you open a JSON file with our application, you can use the following commands:</p>
<ul>
<li><code>validate</code>: Validates the JSON file.</li>
<li><code>print</code>: Prints the JSON file.</li>
<li><code>search &lt;key&gt;</code>: Searches for the key in the JSON and returns its path.</li>
<li><code>contains &lt;value&gt;</code>: Checks if the JSON contains the provided value.</li>
<li><code>set &lt;path&gt; &lt;new_value&gt;</code>: Sets the new value at the given path.</li>
<li><code>create &lt;path&gt; &lt;value&gt;</code>: Creates a new element with the given value at the specified path.</li>
<li><code>delete &lt;path&gt;</code>: Deletes the element at the given path.</li>
<li><code>move &lt;fromPath&gt; &lt;toPath&gt;</code>: Moves the element from the source path to the destination path.</li>
<li><code>save</code> [&lt;path&gt;] saveas &lt;file&gt; [&lt;path&gt;]: Saves the JSON file to the specified path.</li>
</ul>
<h1><a class="anchor" id="classes_sec"></a>
Classes</h1>
<p>The application includes several classes to handle JSON data, including:</p>
<ul>
<li><code><a class="el" href="class_json_manager.html" title="The JsonManager class provides functionalities to manage JSON operations.">JsonManager</a></code>: Manages JSON file operations like opening, saving, etc.</li>
<li><code><a class="el" href="class_json_parser.html" title="This class is responsible for parsing JSON text.">JsonParser</a></code>: Parses JSON data.</li>
<li><code><a class="el" href="class_json_object.html" title="A class that represents an object in JSON.">JsonObject</a></code>, <code><a class="el" href="class_json_array.html" title="A class that represents an array in JSON.">JsonArray</a></code>, <code><a class="el" href="class_json_value.html" title="JSON Value class that implements JsonElement interface.">JsonValue</a></code>: Represent different types of JSON elements.</li>
<li><code><a class="el" href="class_json_key.html" title="A class representing a key in a JSON key-value pair.">JsonKey</a></code>: Represents a key in a JSON object.</li>
<li><code><a class="el" href="class_json_validator.html" title="The JsonValidator class validates a string to check if it&#39;s a correctly formed JSON.">JsonValidator</a></code>: Validates a JSON string.</li>
<li><code>JsonException</code> and its subclasses: Represent various exceptions that can occur while handling JSON data.</li>
</ul>
<p>Detailed information about these classes can be found in the "Classes" section.</p>
<h1><a class="anchor" id="install_sec"></a>
Installation</h1>
<p>To use the JSON Parser Console Application, simply clone the repository and build it using a C++ compiler. The application does not have any external dependencies. </p>
</div></div><!-- PageDoc -->
</div>

# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`JsonArray`](#class_json_array) | A class that represents an array in JSON.
`class `[`JsonElement`](#class_json_element) | An abstract class representing an element in a JSON document.
`class `[`JsonKey`](#class_json_key) | A class representing a key in a JSON key-value pair.
`class `[`JsonManager`](#class_json_manager) | The [JsonManager](#class_json_manager) class provides functionalities to manage JSON operations.
`class `[`JsonObject`](#class_json_object) | A class that represents an object in JSON.
`class `[`JsonParser`](#class_json_parser) | This class is responsible for parsing JSON text.
`class `[`JsonValidator`](#class_json_validator) | The [JsonValidator](#class_json_validator) class validates a string to check if it's a correctly formed JSON.
`class `[`JsonValue`](#class_json_value) | JSON Value class that implements [JsonElement](#class_json_element) interface.

# class `JsonArray`

```
class JsonArray
  : public JsonElement
```  

A class that represents an array in JSON.

The [JsonArray](#class_json_array) class encapsulates a vector of [JsonElement](#class_json_element) pointers and provides methods to manipulate and search the array, in addition to converting the array to a JSON-formatted string.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`JsonArray`](#class_json_array_1a304f5ede160dbc87f9ec7d7983bd1cbf)`()` | Default constructor for [JsonArray](#class_json_array).
`public  `[`~JsonArray`](#class_json_array_1a9ca4578a4a02708517eb6f15e4cd9b8b)`()` | Destructor for [JsonArray](#class_json_array), overridden from [JsonElement](#class_json_element).
`public void `[`add_element`](#class_json_array_1a33c6f0ccbcb938b4b678e7d8f06a3d55)`(`[`JsonElement`](#class_json_element)` * value)` | Add an element to the array.
`public `[`JsonElement`](#class_json_element)` * `[`get_element`](#class_json_array_1abd7b391adb022d6fc32ed76eeb048d19)`(int index)` | Get an element from the array by index.
`public virtual std::string `[`to_string`](#class_json_array_1ae65670649aedfad0375b1f3b8b6a1b20)`() const` | Convert the array to a JSON-formatted string.
`public virtual std::vector< std::string > `[`search`](#class_json_array_1a79a316409a5f3fa8ebab101eb2d1e313)`(const std::string & key)` | Search for a key in the array.
`public virtual bool `[`contains`](#class_json_array_1a1f09fd4a5b4ec045945e3ed9d301c3d9)`(const std::string & value)` | Check if the array contains a value.
`public virtual void `[`set`](#class_json_array_1afa38f83b7b285940d66117104be65748)`(const std::vector< std::string > & path,const std::string & new_value)` | Set the value of an element at a given path.
`public virtual void `[`create`](#class_json_array_1a3869c3769f8d253a7a639c2e0f141688)`(const std::vector< std::string > & path,const std::string & value)` | Create a new element at a given path.
`public virtual void `[`delete_element`](#class_json_array_1ae93c0b17ebef659d034eaeb3dd736ffa)`(const std::vector< std::string > & path)` | Delete an element at a given path.
`public virtual void `[`move`](#class_json_array_1ad86b8c638a507fee7db3d58d43e1d7a1)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)` | Move an element from one path to another.

## Members

#### `public  `[`JsonArray`](#class_json_array_1a304f5ede160dbc87f9ec7d7983bd1cbf)`()`

Default constructor for [JsonArray](#class_json_array).

#### `public  `[`~JsonArray`](#class_json_array_1a9ca4578a4a02708517eb6f15e4cd9b8b)`()`

Destructor for [JsonArray](#class_json_array), overridden from [JsonElement](#class_json_element).

#### `public void `[`add_element`](#class_json_array_1a33c6f0ccbcb938b4b678e7d8f06a3d55)`(`[`JsonElement`](#class_json_element)` * value)`

Add an element to the array.

#### Parameters
* `value` The element to add.

#### `public `[`JsonElement`](#class_json_element)` * `[`get_element`](#class_json_array_1abd7b391adb022d6fc32ed76eeb048d19)`(int index)`

Get an element from the array by index.

#### Parameters
* `index` The index of the element to get.

#### Returns
The element at the given index.

#### `public virtual std::string `[`to_string`](#class_json_array_1ae65670649aedfad0375b1f3b8b6a1b20)`() const`

Convert the array to a JSON-formatted string.

#### Returns
A JSON-formatted string representing the array.

#### `public virtual std::vector< std::string > `[`search`](#class_json_array_1a79a316409a5f3fa8ebab101eb2d1e313)`(const std::string & key)`

Search for a key in the array.

#### Parameters
* `key` The key to search for.

#### Returns
A vector of paths to the elements that contain the key.

#### `public virtual bool `[`contains`](#class_json_array_1a1f09fd4a5b4ec045945e3ed9d301c3d9)`(const std::string & value)`

Check if the array contains a value.

#### Parameters
* `value` The value to check for.

#### Returns
True if the value is found, false otherwise.

#### `public virtual void `[`set`](#class_json_array_1afa38f83b7b285940d66117104be65748)`(const std::vector< std::string > & path,const std::string & new_value)`

Set the value of an element at a given path.

#### Parameters
* `path` The path to the element.

* `new_value` The new value to set.

#### `public virtual void `[`create`](#class_json_array_1a3869c3769f8d253a7a639c2e0f141688)`(const std::vector< std::string > & path,const std::string & value)`

Create a new element at a given path.

#### Parameters
* `path` The path to the new element.

* `value` The value of the new element.

#### `public virtual void `[`delete_element`](#class_json_array_1ae93c0b17ebef659d034eaeb3dd736ffa)`(const std::vector< std::string > & path)`

Delete an element at a given path.

#### Parameters
* `path` The path to the element to delete.

#### `public virtual void `[`move`](#class_json_array_1ad86b8c638a507fee7db3d58d43e1d7a1)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)`

Move an element from one path to another.

#### Parameters
* `fromPath` The current path of the element.

* `toPath` The new path for the element.

# class `JsonElement`

An abstract class representing an element in a JSON document.

[JsonElement](#class_json_element) is a base class for all types of elements that can appear in a JSON document, such as arrays, objects, and primitive values (strings, numbers, booleans, null). It provides a common interface for operations that can be performed on any JSON element, such as converting it to a string, searching for a key, checking for the presence of a value, and modifying its contents.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~JsonElement`](#class_json_element_1a65dbb209b55ae334059698d025783fed)`() = default` | Virtual destructor.
`public std::string `[`to_string`](#class_json_element_1acaa559e1be09dff2f6b347775d0983dc)`() const` | Convert the JSON element to a string.
`public std::vector< std::string > `[`search`](#class_json_element_1a89efc03621132a676694994be0b88ee5)`(const std::string & key)` | Search for a key in the JSON element.
`public bool `[`contains`](#class_json_element_1aff8ec1964ccbfcd7d450d66d9956e3f7)`(const std::string & value)` | Check if the JSON element contains a certain value.
`public void `[`set`](#class_json_element_1a484d825f5e631f899fdff7ddb486a585)`(const std::vector< std::string > & path,const std::string & new_value)` | Set the value at a certain path in the JSON element.
`public void `[`create`](#class_json_element_1a4dd348e9dc77f27397d023405b5bcd45)`(const std::vector< std::string > & path,const std::string & value)` | Create a new key-value pair at a certain path in the JSON element.
`public void `[`delete_element`](#class_json_element_1ac6330f1734e30ed7a316087e68fc6f0f)`(const std::vector< std::string > & path)` | Delete a key-value pair at a certain path in the JSON element.
`public void `[`move`](#class_json_element_1a2ddc931b379e450ce2ebd4e240e5a628)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)` | Move a key-value pair from one path to another in the JSON element.

## Members

#### `public virtual  `[`~JsonElement`](#class_json_element_1a65dbb209b55ae334059698d025783fed)`() = default`

Virtual destructor.

#### `public std::string `[`to_string`](#class_json_element_1acaa559e1be09dff2f6b347775d0983dc)`() const`

Convert the JSON element to a string.

#### Returns
A string representation of the JSON element.

#### `public std::vector< std::string > `[`search`](#class_json_element_1a89efc03621132a676694994be0b88ee5)`(const std::string & key)`

Search for a key in the JSON element.

#### Parameters
* `key` The key to search for.

#### Returns
A vector of strings representing the path to the key, or an empty vector if the key is not found.

#### `public bool `[`contains`](#class_json_element_1aff8ec1964ccbfcd7d450d66d9956e3f7)`(const std::string & value)`

Check if the JSON element contains a certain value.

#### Parameters
* `value` The value to check for.

#### Returns
True if the value is found, false otherwise.

#### `public void `[`set`](#class_json_element_1a484d825f5e631f899fdff7ddb486a585)`(const std::vector< std::string > & path,const std::string & new_value)`

Set the value at a certain path in the JSON element.

#### Parameters
* `path` A vector of strings representing the path to the value.

* `new_value` The new value to set.

#### `public void `[`create`](#class_json_element_1a4dd348e9dc77f27397d023405b5bcd45)`(const std::vector< std::string > & path,const std::string & value)`

Create a new key-value pair at a certain path in the JSON element.

#### Parameters
* `path` A vector of strings representing the path to the new key-value pair.

* `value` The value to set for the new key.

#### `public void `[`delete_element`](#class_json_element_1ac6330f1734e30ed7a316087e68fc6f0f)`(const std::vector< std::string > & path)`

Delete a key-value pair at a certain path in the JSON element.

#### Parameters
* `path` A vector of strings representing the path to the key-value pair to delete.

#### `public void `[`move`](#class_json_element_1a2ddc931b379e450ce2ebd4e240e5a628)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)`

Move a key-value pair from one path to another in the JSON element.

#### Parameters
* `fromPath` A vector of strings representing the current path of the key-value pair.

* `toPath` A vector of strings representing the new path for the key-value pair.

# class `JsonKey`

A class representing a key in a JSON key-value pair.

The [JsonKey](#class_json_key) class encapsulates a string key used in a JSON object. The key can be obtained or modified through accessor methods, and can be converted to a JSON-formatted string.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  explicit `[`JsonKey`](#class_json_key_1a251455a554c09cb155f0c0424bed06d0)`(const std::string & key)` | Construct a new [JsonKey](#class_json_key) object with a given key.
`public inline std::string `[`get_key`](#class_json_key_1ae101c7d8daebff9af2374a001c08edaf)`() const` | Get the encapsulated key.
`public inline void `[`set_key`](#class_json_key_1ade25bc3d303fe67dbf132baf2d911f9c)`(const std::string & newKey)` | Set the encapsulated key.
`public inline std::string `[`to_string`](#class_json_key_1a20aceec919d27e8824b47b64277341b4)`() const` | Convert the encapsulated key to a JSON-formatted string.

## Members

#### `public inline  explicit `[`JsonKey`](#class_json_key_1a251455a554c09cb155f0c0424bed06d0)`(const std::string & key)`

Construct a new [JsonKey](#class_json_key) object with a given key.

#### Parameters
* `key` The string to use as the key.

#### `public inline std::string `[`get_key`](#class_json_key_1ae101c7d8daebff9af2374a001c08edaf)`() const`

Get the encapsulated key.

#### Returns
The encapsulated key.

#### `public inline void `[`set_key`](#class_json_key_1ade25bc3d303fe67dbf132baf2d911f9c)`(const std::string & newKey)`

Set the encapsulated key.

#### Parameters
* `newKey` The new string to use as the key.

#### `public inline std::string `[`to_string`](#class_json_key_1a20aceec919d27e8824b47b64277341b4)`() const`

Convert the encapsulated key to a JSON-formatted string.

#### Returns
A JSON-formatted string representing the key.

# class `JsonManager`

The [JsonManager](#class_json_manager) class provides functionalities to manage JSON operations.

[JsonManager](#class_json_manager) uses a [JsonParser](#class_json_parser) to parse the JSON, and provides operations like opening, saving, validating, printing, searching, checking containment, setting, creating, deleting, and moving elements within a JSON.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`JsonManager`](#class_json_manager_1aa59244b57e3e2464b6eb304ccab55a8a)`()` | Default constructor for [JsonManager](#class_json_manager).
`public  `[`~JsonManager`](#class_json_manager_1ade81448ded6365c5eb6b221106287167)`()` | Destructor for [JsonManager](#class_json_manager).
`public void `[`open`](#class_json_manager_1a9c7da9043a8ea2e1a2abd0dc80aacd0a)`(const std::string & filePath)` | Opens a JSON file.
`public void `[`save`](#class_json_manager_1a99193595221737461254a7ac1070f094)`()` | Saves the current JSON to the file path.
`public void `[`saveAs`](#class_json_manager_1abee72a29e0831cda8677e8580f873f39)`(const std::string & filePath)` | Saves the current JSON to a new file path.
`public void `[`exit`](#class_json_manager_1ae27c26642d8bc720664575d41559a3a8)`()` | Exits the [JsonManager](#class_json_manager).
`public bool `[`validate`](#class_json_manager_1abd264c8052df90523e74a2d16aa11b01)`()` | Validates the JSON file.
`public void `[`print`](#class_json_manager_1a7d9abbe836ab188e9557243d0009de6f)`()` | Prints the JSON to the console.
`public std::vector< std::string > `[`search`](#class_json_manager_1ae06d1273d38e97c73a0664bbd9954b6e)`(const std::string & key)` | Searches the JSON for a key.
`public bool `[`contains`](#class_json_manager_1a053445c350b3ffcea0496323660a5a8c)`(const std::string & value)` | Checks if the JSON contains a value.
`public void `[`set`](#class_json_manager_1af5a3960c3006c90f0d807437b0e9b766)`(const std::string & path,const std::string & new_value)` | Sets a value in the JSON.
`public void `[`create`](#class_json_manager_1ad0c5ce51d3704bd940cd1bf611ff31de)`(const std::string & path,const std::string & value)` | Creates a new key-value pair in the JSON.
`public void `[`delete_element`](#class_json_manager_1a9cee399626899e3d7e89c34b10c2ec61)`(const std::string & path)` | Deletes an element in the JSON.
`public void `[`move`](#class_json_manager_1a3acb1531a5d27032a7914bfd1f1874a1)`(const std::string & fromPath,const std::string & toPath)` | Moves an element from one location to another in the JSON.

## Members

#### `public  `[`JsonManager`](#class_json_manager_1aa59244b57e3e2464b6eb304ccab55a8a)`()`

Default constructor for [JsonManager](#class_json_manager).

#### `public  `[`~JsonManager`](#class_json_manager_1ade81448ded6365c5eb6b221106287167)`()`

Destructor for [JsonManager](#class_json_manager).

#### `public void `[`open`](#class_json_manager_1a9c7da9043a8ea2e1a2abd0dc80aacd0a)`(const std::string & filePath)`

Opens a JSON file.

#### Parameters
* `filePath` The path to the JSON file.

#### `public void `[`save`](#class_json_manager_1a99193595221737461254a7ac1070f094)`()`

Saves the current JSON to the file path.

#### `public void `[`saveAs`](#class_json_manager_1abee72a29e0831cda8677e8580f873f39)`(const std::string & filePath)`

Saves the current JSON to a new file path.

#### Parameters
* `filePath` The new path to save the JSON file.

#### `public void `[`exit`](#class_json_manager_1ae27c26642d8bc720664575d41559a3a8)`()`

Exits the [JsonManager](#class_json_manager).

#### `public bool `[`validate`](#class_json_manager_1abd264c8052df90523e74a2d16aa11b01)`()`

Validates the JSON file.

#### Returns
true if the JSON file is valid, false otherwise.

#### `public void `[`print`](#class_json_manager_1a7d9abbe836ab188e9557243d0009de6f)`()`

Prints the JSON to the console.

#### `public std::vector< std::string > `[`search`](#class_json_manager_1ae06d1273d38e97c73a0664bbd9954b6e)`(const std::string & key)`

Searches the JSON for a key.

#### Parameters
* `key` The key to search for.

#### Returns
A vector of strings with the path to the key.

#### `public bool `[`contains`](#class_json_manager_1a053445c350b3ffcea0496323660a5a8c)`(const std::string & value)`

Checks if the JSON contains a value.

#### Parameters
* `value` The value to check for.

#### Returns
true if the JSON contains the value, false otherwise.

#### `public void `[`set`](#class_json_manager_1af5a3960c3006c90f0d807437b0e9b766)`(const std::string & path,const std::string & new_value)`

Sets a value in the JSON.

#### Parameters
* `path` The path to the value to set.

* `new_value` The new value to set.

#### `public void `[`create`](#class_json_manager_1ad0c5ce51d3704bd940cd1bf611ff31de)`(const std::string & path,const std::string & value)`

Creates a new key-value pair in the JSON.

#### Parameters
* `path` The path to the place to create the new key-value pair.

* `value` The value of the new key-value pair.

#### `public void `[`delete_element`](#class_json_manager_1a9cee399626899e3d7e89c34b10c2ec61)`(const std::string & path)`

Deletes an element in the JSON.

#### Parameters
* `path` The path to the element to delete.

#### `public void `[`move`](#class_json_manager_1a3acb1531a5d27032a7914bfd1f1874a1)`(const std::string & fromPath,const std::string & toPath)`

Moves an element from one location to another in the JSON.

#### Parameters
* `fromPath` The path to the element to move.

* `toPath` The path to the new location for the element.

# class `JsonObject`

```
class JsonObject
  : public JsonElement
```  

A class that represents an object in JSON.

The [JsonObject](#class_json_object) class encapsulates a vector of key-value pairs where the key is a [JsonKey](#class_json_key) pointer and the value is a [JsonElement](#class_json_element) pointer. The class provides methods to manipulate, search, and convert the object to a JSON-formatted string.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`JsonObject`](#class_json_object_1aa41d053fc27e4fcf4f1c6f55ef28f4a9)`()` | Default constructor for [JsonObject](#class_json_object).
`public  `[`~JsonObject`](#class_json_object_1a9c99921d0fd1f9e401609d2fdef6ba22)`()` | Destructor for [JsonObject](#class_json_object), overridden from [JsonElement](#class_json_element).
`public void `[`add_element`](#class_json_object_1a36973ccf370b1e995beaa97d485765da)`(`[`JsonKey`](#class_json_key)` * key,`[`JsonElement`](#class_json_element)` * value)` | Add a key-value pair to the object.
`public `[`JsonElement`](#class_json_element)` * `[`get_element`](#class_json_object_1ab3225eee55311a06311dd4d67606797e)`(const std::string & key)` | Get the value associated with a given key in the object.
`public virtual std::string `[`to_string`](#class_json_object_1a68d96ac09e41acba1492abc5ec1a0eea)`() const` | Convert the object to a JSON-formatted string.
`public virtual std::vector< std::string > `[`search`](#class_json_object_1a096210e59d3c570a970944cda0486274)`(const std::string & key)` | Search for a key in the object.
`public virtual bool `[`contains`](#class_json_object_1ae008482ab6e401e07187766c1a4e006a)`(const std::string & value)` | Check if the object contains a value.
`public virtual void `[`set`](#class_json_object_1ae30d3d2fa69c1a965f489bf6a8146c53)`(const std::vector< std::string > & path,const std::string & new_value)` | Set the value of an element at a given path.
`public virtual void `[`create`](#class_json_object_1ab3d665ec4299314e1aef378e60e0a0ca)`(const std::vector< std::string > & path,const std::string & value)` | Create a new element at a given path.
`public virtual void `[`delete_element`](#class_json_object_1ac6fc5f1ed2cd446dfb5a775f432f76d2)`(const std::vector< std::string > & path)` | Delete an element at a given path.
`public virtual void `[`move`](#class_json_object_1a9c475b7b6466243971fe706db3ec96c5)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)` | Move an element from one path to another.

## Members

#### `public  `[`JsonObject`](#class_json_object_1aa41d053fc27e4fcf4f1c6f55ef28f4a9)`()`

Default constructor for [JsonObject](#class_json_object).

#### `public  `[`~JsonObject`](#class_json_object_1a9c99921d0fd1f9e401609d2fdef6ba22)`()`

Destructor for [JsonObject](#class_json_object), overridden from [JsonElement](#class_json_element).

#### `public void `[`add_element`](#class_json_object_1a36973ccf370b1e995beaa97d485765da)`(`[`JsonKey`](#class_json_key)` * key,`[`JsonElement`](#class_json_element)` * value)`

Add a key-value pair to the object.

#### Parameters
* `key` The key to add.

* `value` The value to add.

#### `public `[`JsonElement`](#class_json_element)` * `[`get_element`](#class_json_object_1ab3225eee55311a06311dd4d67606797e)`(const std::string & key)`

Get the value associated with a given key in the object.

#### Parameters
* `key` The key associated with the value to get.

#### Returns
The value associated with the given key.

#### `public virtual std::string `[`to_string`](#class_json_object_1a68d96ac09e41acba1492abc5ec1a0eea)`() const`

Convert the object to a JSON-formatted string.

#### Returns
A JSON-formatted string representing the object.

#### `public virtual std::vector< std::string > `[`search`](#class_json_object_1a096210e59d3c570a970944cda0486274)`(const std::string & key)`

Search for a key in the object.

#### Parameters
* `key` The key to search for.

#### Returns
A vector of paths to the elements that contain the key.

#### `public virtual bool `[`contains`](#class_json_object_1ae008482ab6e401e07187766c1a4e006a)`(const std::string & value)`

Check if the object contains a value.

#### Parameters
* `value` The value to check for.

#### Returns
True if the value is found, false otherwise.

#### `public virtual void `[`set`](#class_json_object_1ae30d3d2fa69c1a965f489bf6a8146c53)`(const std::vector< std::string > & path,const std::string & new_value)`

Set the value of an element at a given path.

#### Parameters
* `path` The path to the element.

* `new_value` The new value to set.

#### `public virtual void `[`create`](#class_json_object_1ab3d665ec4299314e1aef378e60e0a0ca)`(const std::vector< std::string > & path,const std::string & value)`

Create a new element at a given path.

#### Parameters
* `path` The path to the new element.

* `value` The value of the new element.

#### `public virtual void `[`delete_element`](#class_json_object_1ac6fc5f1ed2cd446dfb5a775f432f76d2)`(const std::vector< std::string > & path)`

Delete an element at a given path.

#### Parameters
* `path` The path to the element to delete.

#### `public virtual void `[`move`](#class_json_object_1a9c475b7b6466243971fe706db3ec96c5)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)`

Move an element from one path to another.

#### Parameters
* `fromPath` The current path of the element.

* `toPath` The new path for the element.

# class `JsonParser`

This class is responsible for parsing JSON text.

It reads a string of JSON text and constructs an in-memory representation of the JSON using `[JsonValue](#class_json_value)`, `[JsonArray](#class_json_array)`, and `[JsonObject](#class_json_object)` objects. The parsing process includes validation of the JSON text structure according to the JSON standard.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`JsonParser`](#class_json_parser_1ab2bfea1ba43bf7110d05bd1537cd3f90)`(const std::string & jsonStream)` | Constructs a new Json Parser object.
`public `[`JsonElement`](#class_json_element)` * `[`parse`](#class_json_parser_1a95c7513cd7b8c7f09a2deda73c019bb4)`()` | Begins parsing the JSON text.

## Members

#### `public  explicit `[`JsonParser`](#class_json_parser_1ab2bfea1ba43bf7110d05bd1537cd3f90)`(const std::string & jsonStream)`

Constructs a new Json Parser object.

#### Parameters
* `jsonStream` The JSON text to parse.

#### `public `[`JsonElement`](#class_json_element)` * `[`parse`](#class_json_parser_1a95c7513cd7b8c7f09a2deda73c019bb4)`()`

Begins parsing the JSON text.

#### Returns
A pointer to the root `[JsonElement](#class_json_element)` object representing the parsed JSON.

# class `JsonValidator`

The [JsonValidator](#class_json_validator) class validates a string to check if it's a correctly formed JSON.

[JsonValidator](#class_json_validator) has a static method [validate()](#class_json_validator_1a5614538dd8fe80b904bf3dc9b028d0bc) that checks if the given string forms a valid JSON.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `JsonValue`

```
class JsonValue
  : public JsonElement
```  

JSON Value class that implements [JsonElement](#class_json_element) interface.

[JsonValue](#class_json_value) class represents a JSON value which could be of type: String, Number, Bool, Object or Array.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`JsonValue`](#class_json_value_1aba2587eefca1ad50f946b0202bda7767)`()` | Default constructor for [JsonValue](#class_json_value).
`public  explicit `[`JsonValue`](#class_json_value_1a6101e8292a02da86d5321c8ae8a934cd)`(const std::string & value)` | Constructor for creating a [JsonValue](#class_json_value) of type string.
`public  explicit `[`JsonValue`](#class_json_value_1abcea4ddd4925c5f17007a030ae025c81)`(double value)` | Constructor for creating a [JsonValue](#class_json_value) of type number.
`public  explicit `[`JsonValue`](#class_json_value_1ae3242123655bc487e5c946f517e062f4)`(bool value)` | Constructor for creating a [JsonValue](#class_json_value) of type bool.
`public  explicit `[`JsonValue`](#class_json_value_1a42658f6d2ca756c35ef65cb71b095cd6)`(`[`JsonArray`](#class_json_array)` * value)` | Constructor for creating a [JsonValue](#class_json_value) of type [JsonArray](#class_json_array).
`public  explicit `[`JsonValue`](#class_json_value_1aefbd2827747eea9f887441be8cf6b519)`(`[`JsonObject`](#class_json_object)` * value)` | Constructor for creating a [JsonValue](#class_json_value) of type [JsonObject](#class_json_object).
`public virtual std::string `[`to_string`](#class_json_value_1a8ad1e0635db285f3f0b525b144260fc3)`() const` | Converts [JsonValue](#class_json_value) to a string representation.
`public virtual std::vector< std::string > `[`search`](#class_json_value_1a39576338933618f8f47cee8e6141979b)`(const std::string & key)` | Search for a key in [JsonValue](#class_json_value).
`public virtual bool `[`contains`](#class_json_value_1a340e8d17bc44d0618fc82f48f0202dc4)`(const std::string & value)` | Check if [JsonValue](#class_json_value) contains a specific string value.
`public virtual void `[`set`](#class_json_value_1ab859138a2fa51b49669f8bc6c659e9c1)`(const std::vector< std::string > & path,const std::string & new_value)` | Sets a new value in a [JsonValue](#class_json_value) using a path.
`public virtual void `[`create`](#class_json_value_1accce4336f6462bd1572fe09cfb8ba420)`(const std::vector< std::string > & path,const std::string & value)` | Creates a new [JsonValue](#class_json_value) using a path.
`public virtual void `[`delete_element`](#class_json_value_1a22721a96f72f09a56e2004f24ea80eee)`(const std::vector< std::string > & path)` | Deletes an element in a [JsonValue](#class_json_value) using a path.
`public virtual void `[`move`](#class_json_value_1a48f892b291985cc0e8e5d1804a4776ec)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)` | Moves an element from one path to another.

## Members

#### `public  `[`JsonValue`](#class_json_value_1aba2587eefca1ad50f946b0202bda7767)`()`

Default constructor for [JsonValue](#class_json_value).

#### `public  explicit `[`JsonValue`](#class_json_value_1a6101e8292a02da86d5321c8ae8a934cd)`(const std::string & value)`

Constructor for creating a [JsonValue](#class_json_value) of type string.

#### Parameters
* `value` The string value.

#### `public  explicit `[`JsonValue`](#class_json_value_1abcea4ddd4925c5f17007a030ae025c81)`(double value)`

Constructor for creating a [JsonValue](#class_json_value) of type number.

#### Parameters
* `value` The number value.

#### `public  explicit `[`JsonValue`](#class_json_value_1ae3242123655bc487e5c946f517e062f4)`(bool value)`

Constructor for creating a [JsonValue](#class_json_value) of type bool.

#### Parameters
* `value` The bool value.

#### `public  explicit `[`JsonValue`](#class_json_value_1a42658f6d2ca756c35ef65cb71b095cd6)`(`[`JsonArray`](#class_json_array)` * value)`

Constructor for creating a [JsonValue](#class_json_value) of type [JsonArray](#class_json_array).

#### Parameters
* `value` The [JsonArray](#class_json_array) value.

#### `public  explicit `[`JsonValue`](#class_json_value_1aefbd2827747eea9f887441be8cf6b519)`(`[`JsonObject`](#class_json_object)` * value)`

Constructor for creating a [JsonValue](#class_json_value) of type [JsonObject](#class_json_object).

#### Parameters
* `value` The [JsonObject](#class_json_object) value.

#### `public virtual std::string `[`to_string`](#class_json_value_1a8ad1e0635db285f3f0b525b144260fc3)`() const`

Converts [JsonValue](#class_json_value) to a string representation.

#### Returns
A JSON-formatted string representing the object.

#### `public virtual std::vector< std::string > `[`search`](#class_json_value_1a39576338933618f8f47cee8e6141979b)`(const std::string & key)`

Search for a key in [JsonValue](#class_json_value).

#### Parameters
* `key` The key to search for.

#### Returns
A vector of paths to the elements that contain the key.

#### `public virtual bool `[`contains`](#class_json_value_1a340e8d17bc44d0618fc82f48f0202dc4)`(const std::string & value)`

Check if [JsonValue](#class_json_value) contains a specific string value.

#### Parameters
* `value` The value to check for.

#### Returns
True if the value is found, false otherwise.

#### `public virtual void `[`set`](#class_json_value_1ab859138a2fa51b49669f8bc6c659e9c1)`(const std::vector< std::string > & path,const std::string & new_value)`

Sets a new value in a [JsonValue](#class_json_value) using a path.

#### Parameters
* `path` The path to the element.

* `new_value` The new value to set.

#### `public virtual void `[`create`](#class_json_value_1accce4336f6462bd1572fe09cfb8ba420)`(const std::vector< std::string > & path,const std::string & value)`

Creates a new [JsonValue](#class_json_value) using a path.

#### Parameters
* `path` The path to the new element.

* `value` The value of the new element.

#### `public virtual void `[`delete_element`](#class_json_value_1a22721a96f72f09a56e2004f24ea80eee)`(const std::vector< std::string > & path)`

Deletes an element in a [JsonValue](#class_json_value) using a path.

#### Parameters
* `path` The path to the element to delete.

#### `public virtual void `[`move`](#class_json_value_1a48f892b291985cc0e8e5d1804a4776ec)`(const std::vector< std::string > & fromPath,const std::vector< std::string > & toPath)`

Moves an element from one path to another.

#### Parameters
* `fromPath` The current path of the element.

* `toPath` The new path for the element.

Generated by [Moxygen](https://sourcey.com/moxygen)
/*! \mainpage Search and Rescue Drone Project Home
 *
 * \section intro_sec Introduction
 *
 * This is currently the first Interation of our search and rescue drone project.
 * This project upon completion will create a simulated search and rescue drone after a total of 3 iterations.
 * 
 * \section howto_sec How to Build and Run the Project
 * 
 * To build and run the project on a Linux operating system there are three simple steps:
 * 1. Import your original image(s) into the directory of the project (preferably in a "data" directory)
 * 2. Navigate to the project directory in your terminal and type "make" in the shell. THe project is now built.
 * 3. In the shell, type "./image_processor <path_to_origin_image> <filter_to_be_applied> <path_to_filtered_image>
 * 
 * Once the program has run you should see your image with the given filter in whatever file path you selected.
 * 
 * \section classoverview_sec Overview of the Main Classes
 * 
 *There are several classes involved in the making of this project. Below is a brief synopsis of the major classes.
 * For a more detailed description of all the classes select the class tab.
 * 
 * Image_Processor: This is the functionality of the project and is used to build all the filters based on user input.
 * Image: This is the main class of the proejct it creats a class object of the image and inlcludes the methods for saving and importing the images among other things.
 * Filter: This is the parent class to all of the various filters it links htem together for simplicity.
 * Color: This class is used to create a class object or description of each pixel in the image and stores the pixel's red, green, blue, and alpha values.
 * Kernel: This class is used in a few of the filters to create a "mini image" my storing the color values of the [ixels surronding any given pixel in order to manipulate the pixels.
 * 
 * \section extension_sec How to Extend the System
 * 
 * In order to extend the project (create more filters) they must inheirt from the filter class itself and they may have dependcies to color, kernel, and image as well.
 * A new feature branch must be added on the git repository titled feature/<new_filter_name> and the code for the filter must be created and added there.
 * Upon completion the code must be pushed to git and a pull request may be created to add the filter to the develop branch. The pull request will require another developer to review the code.
 * Once reviewed the code may be pushed to the main branch to be finalized where it must be pulled and reviewed by at least two other developers.
 * After final reviews are completed the code is added to main and the filter is successfully added to the project. 
 */

Setting up Visual Studio
************************

Freeciv21 can be compiled using Microsoft Visual Studio |reg| and :file:`clang-cl`. This page will help you
get version 2022 up and running.

.. warning:: Visual Studio and the corresponding dependencies require a great deal of HDD space on your
   computer. Be sure to have at least 50GB of available space before starting this process.


Base Installation
=================

Start by `downloading <https://visualstudio.microsoft.com/vs/community/>`_ the Community Edition installer.

Double-click the :file:`VisualStudioSetup.exe` file in your Downloads directory and follow the prompts to
get the setup process started. At some point you will be prompted to select the type of workload you want to
install. Select :guilabel:`Desktop development with C++` and :guilabel:`Python Development`. Next click on the
Individual components tab and select the following options: :guilabel:`Git for Windows`,
:guilabel:`C++ Clang Compiler for Windows (13.0.0)`, :guilabel:`C++ Clang-cl for v143 build tools (x64/x86)`,
and :guilabel:`Python 3 64-bit (3.9.7)`.

When ready click :guilabel:`Install`. Depending on your Internet connection speed, this may take a while.

When the installation process is finished you may be presented with a collection of options. You don't need
Visual Studio right now, so best to close everything at this point.

Set Up VCPKG
============

:file:`vcpkg` is a library package manager developed by Microsoft. It makes downloading and installing
third-party libraries much easier. Freeciv21 uses :file:`vcpkg` in this way via the manifest file
:file:`vcpkg.json`. Documentation is available here: https://github.com/microsoft/vcpkg

First, create a directory on your computer to install :file:`vcpkg` into. For example: :file:`C:\\Tools`.
The directory can be anywhere, however the author prefers to :strong:`not` install things in the root of the
:file:`C:\\` drive.

Open an Administrative elevated PowerShell terminal window. The easiest way to do this is to right-click on the
:guilabel:`Start Menu` and select it from the menu: :guilabel:`Windows PowerShell (Admin)`.

.. code-block:: rst

    PS C:\Windows\System32> cd c:\tools
    PS C:\Tools>


Follow these steps to install :file:`vcpkg`. The :file:`setx` command should be altered to be the correct path
that you installed :file:`vcpkg` into. The forward slashes are correct.

.. code-block:: rst

    Tools> git clone https://github.com/microsoft/vcpkg
    Tools> .\vcpkg\bootstrap-vcpkg.bat
    Tools> setx VCPKG_ROOT C:/Tools/vcpkg /M
    Tools> exit


.. warning:: The :file:`vcpkg` website/readme will ask for you to run a :file:`vcpkg integrate install` command
  to fully integrate all the packages installed into Visual Studio. :strong:`Do Not` run this command as it
  actually breaks Visual Studio's ability to find and use the :file:`clang-cl` compiler, which we need.

GitHub
======

The Longturn.net Community uses the online source code control and revision system known as
`GitHub <https://github.com/>`_. To contribute, you will need an account on this platform. There is no cost.

With an account, you can go to the `Longturn <https://github.com/longturn>`_ community repository page and
:strong:`fork` a repository (such as the Freeciv21 repository) to your personal GitHub account. Go to the main
page of the repository you want to fork and you will find a :strong:`fork` button in the upper-right corner.

In order to get code pushed to the forked repository to your local workstation, you need to setup an
SSH key pair to share with GitHub. Follow these
`instructions <https://docs.github.com/en/authentication/connecting-to-github-with-ssh>`_.

With SSH set up, now it's time to clone the forked repository from your personal GitHub account to a local
copy on your workstation. You can get the appropriate path by going to your forked copy in a browser, click
the code button and then select the SSH option as shown in this sample screenshot:

.. image:: ../_static/images/github_clone_ssh.png
    :align: center
    :height: 250
    :alt: GitHub Clone SSH


Open up Visual Studio. A menu will appear. Go to the very bottom right and click the link to
:strong:`continue without code`. Select :menuselection:`View --> Terminal` to open a terminal in the IDE if
one is not already shown at the bottom. Once you have the proper GitHub path, here is the command to clone
the repository:

.. code-block:: rst

    PS C:\Users\[user]\Source\Repos> git clone git@github.com:[username]/freeciv21.git


This will clone the forked repository to the :file:`C:\\Users\\[User]\\Source\\Repos\\freeciv21` directory on
your computer.

The final repository setup item is to link the original Longturn project repository to your local area on
your computer:

.. code-block:: rst

    Repos> cd freeciv21
    Repos\freeciv21> git remote add upstream https://github.com/longturn/freeciv21.git
    Repos\freeciv21> git fetch upstream
    Repos\freeciv21> git pull upstream master


You will also need to set a couple global configuration settings so :code:`git` knows a bit more about you.

.. code-block:: rst

    freeciv21> git config --global user.email "[email address associated with GitHub]"
    freeciv21> git config --global user.name "[your first and last name]"


Build Visual Studio Solution
============================

Now let's get Visual Studio set up. Select :menuselection:`Git --> Local Repositories --> Open Local Repository`
and then select the :file:`freeciv21` folder. Visual Studio will take a minute to parse the source tree.

Select :menuselection:`File --> Open --> Folder`. Select the :file:`freeciv21` directory and then Visual Studio
will parse the files in there. It can take a few mintues for this to complete. When complete, Visual Studio
will open a :strong:`CMake Overview Pages` tab.

Microsoft provides documentation on CMake in Visual Studio --
https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170


Final Steps and Notes
=====================

At this point Visual Studio is ready for you to configure, compile (build), and install Freeciv21. 

To configure Freeciv21 in Visual Studio you first have to select either the :file:`windows-release` or
:file:`windows-debug` configuration preset as defined in :file:`CMakePresets.json`. On the :guilabel:`Standard`
toolbar, which is enabled by default, you will click the :guilabel:`Target System` drop down box and pick the
:strong:`Local Machine` option. Next you will click the :guilabel:`Configuration` drop down box and pick the
:strong:`windows-release` or :strong:`windows-debug` option. Visual Studio will then automatically populate the
:guilabel:`Build Preset` drop down box based on what you select for :guilabel:`Configuration`. With these options
set you will lastly click :menuselection:`Project --> Configure Cache`. When this process is complete you can
then compile (build) by clicking :menuselection:`Build --> Build All`. Visual Studio will compile all targets
for Freeciv21 and place the output into the :file:`build-vs` directory. If you want to install Freeciv21 to test
any work you are doing, you can go to :menuselection:`Build --> install Freeciv21`. When complete, you should find
a fully functional install in the :file:`build-vs/install` directory.

.. note:: The first time you run the Configure Cache command (from :menuselection:`Project --> Configure Cache`)
  or ask Visual Studio to generate the C++ Intellisense data, Visual Studio will invoke the :file:`vcpkg`
  installation process to download and compile all of the project dependencies listed in the manifest file:
  :file:`vcpkg.json`. :strong:`This will take a very long time`. On a fast computer with a good Internet connection
  it will take at least 3 hours to complete. Everything will be downloaded and compiled into the
  :file:`C:\\Tools\\vcpkg` directory, or wherever you configured :file:`vcpkg` earlier. Binaries for the packages
  will be copied into the :file:`./build-vs/` directory inside of the main Freeciv21 directory and reused for
  subsequent builds.

.. attention:: As documented in :doc:`../General/install`, there is a :file:`--target package` option available
  to build a installable package for Windows. This is only available to the MSYS2 environment. This does not
  mean that you can not test an install using Visual Studio. After going to
  :menuselection:`Build --> install Freeciv21` you can still manually start up the client or a server as needed
  to debug. To do this you will start up either the client, the server, or both and then in Visual Studio go to
  :menuselection:`Debug --> Attach to Process`

:strong:`Notes about Clang-Cl vs MSVC`

Freeciv21 has two custom presets specifically for Windows and Visual Studio because Visual Studio defaults to the
MSVC compiler instead of LLVM's Clang-Cl compiler that we installed earlier. The main reason why we do this is
because the code requires proprietary extensions that MSVC doesn't implement. Instead the Longturn community supports
the open source LLVM Clang-Cl compiler on Windows in Visual Studio as it supports the required proprietary
extensions (note that GNU GCC is used in :doc:`MSYS2 <msys2>` on Windows). If you select any preset and allow
Visual Studio to configure with the Ninja generator and MSVC compiler you will recieve a great number of errors
and the build will fail.

If you are interested in configuring and compiling from the command line instead of the GUI, you can use
these commands:

.. code-block:: rst

  cmake . -B build-vs -G "Visual Studio 17 2022" -DCMAKE_INSTALL_PREFIX=./build-vs/install
  cmake --build build-vs
  cmake --build build-vs --target install


The first command configures Visual Studio to compile a Debug version of the programs and places the install
location to be a sub-directory of the :file:`build-vs` directory for use during debugging and testing purposes.
This is the same as selecting the :file:`windows-debug` preset configuration. The second and third command then
"builds" and "installs" the configured code solution. You will need to manually start the client and/or server to
test.


.. |reg|    unicode:: U+000AE .. REGISTERED SIGN
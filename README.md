<div>
  <div align="center">
    <img src="https://avatars.githubusercontent.com/u/91300229?s=400&u=9519ad33ea9af71ef9b8f4d249fd3155a89ab84c&v=4" width="200px">
    <div align="center">
     <img src="https://img.shields.io/github/workflow/status/vcwild/feminist-api/build-test-pipeline" />
     <img src="https://img.shields.io/tokei/lines/github/vcwild/feminist-api"/>
     <img src="https://img.shields.io/github/license/vcwild/feminist-api" />
    </div>
  </div>
</div>

# FaceTattoo Projects API

API REST model that can be used in a variety of aplications, in this example, and by default, it's running a model of an API REST for access 42 projects. 

## Table of contents

- [Tech stack](#tech-stack)
- [How to run](#how-to-run)
- [How to develop](#development-builds)
- [How to use the CLI](#using-the-cli)
- [Install the program](#install-the-program)
- [API declaration](docs/api.md)
- [Contribute](#contribute)
- [License](#LICENSE)

## What is this?

## Tech stack

- ANSI C
- Docker
- GNU Make
- Mongoose web server
- OpenSSL
- Jansson
- MySQL
- Rhonabwy

## How to run

You can run this API locally, but you will need to run in parallel a MariaDB container. We strongly recommend you to run it using our docker-compose.yml file to create 2 containers. In this method is needed you to change the IP in the file docker-compose.yml to match yours, otherwise you'll have database connection problem. 

### Requirements

This API REST has only Debian based linux support, and all that you need to run is the Docker and Docker Compose package.

#### DevTools for Debian/Ubuntu

In order to install the build essentials, run the following command:

```sh
sudo apt-get install docker && sudo apt-get install docker-compose
```

### Method 1 - Use our container build

 Simply run our docker-compose.yml file with the following command:

```sh
# This for getting the docker composo file:

wget https://raw.githubusercontent.com/Face-Tattoo/Api_Labs/main/docker-compose.yml\?token\=GHSAT0AAAAAABRADJ3ZMAQ7E3OQUC3FZZBMYQ3WKJQ -o docker-compose.yml

# Now change the docker compose file using the text editor of your like, in this example we will use vim. 

nano docker-compose.yml

# Now run the docker compose file, this may take a while depending on your internet connection. 

docker-compose -f "docker-compose.yml" up -d --build
```
### Method 2 - Locally

Clone the repository and install all dependecies.

```sh
# Use the make install to install some dependecies, if some error occour, see the list of dependecies and try to install with another method. 

make install

# Now initialize the mariadb database container

docker run -d --name mariadb -p 3306:3306 -e MYSQL_ROOT_PASSWORD=mariadb -e MYSQL_DATABASE=42api mariadb:latest

# Or install mariadb locally too

sudo apt install maridb-server
sudo mysql_secure_installation

# For the password root
mariadb

# Create a DB this will entry in your mariadb
mysql -pmariadb

# This will create the DB
CREATE DATABASE 42api;
exit

#Run the .sh file, this will create the tables in the DB and initialize the server. 
./run.sh
```

## How to test

We create tests with Insomnia that is an aplication that create and test http request, this is not a automated test but it is functional to verify if the server is running and receiving API REST instructions. 

- For this you will need to download [Insomnia](https://insomnia.rest/download)

- Then you will need to import the insomnia_tests.json from the repository.

- Open the Insomnia aplication.

- Go to the gear icon.

- In the Data file, select the import data option.

- Select From File and select the insomnia_tests.json file. 

- In the dashboard enter in the document just created

- After that, go to the DEBUG tab and enter in the Dropdown menu No enviroment

- In this file, you need to change the in the IP in the file with your machine IP, the same IP that you used in previous steps.

- It should look like this. 

```json
{
	"base_url": "YOUR_IP-HERE:8000",
	"token": "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJleHAiOjE3MjgwMH0.ddOza6DgJ92OvnC5v5sx1bGW7-9wMUk5Rbey9SxELDI"
}
```

- After that, go to the TEST tab and select Run Tests. 

### Development server

Development server is ready-only only if you used the Method-1. Making a development server using the Method-2 is counterproductive.

## Using the CLI

The server logs can be accessed via the `ada` command line interface. This step assumes that the server is already running.

### Running the CLI from within a docker container

This step assumes that you already have the [server running in a docker container](#how-to-run).

Execute `Logs` commands through the docker interface:

```sh
docker exec -it 42api Logs --help
```

You can also make an alias for that, to make this process easier:

```sh
alias Logs="docker exec -it 42api Logs"
```

Or you can use our other Cli thats use the Database logs for the Cli, this have more option to see the logs.

```sh
docker exec -it 42api Logs2 --help
# and create a alias out of the docker 
alias Logs2="docker exec -it 42api Logs2"
```

### Running the CLI locally

This step assumes that you followed the [how to develop](#how-to-develop) guide.

```sh
# inside of the repository folder
make logs_local

#this will create the to types of logs then you choose yours 
./Logs
# or
./Logs2
```

## Contribute

This project was made by [Luiz](https://github.com/luizlcezario), [Van Antonnie](https://github.com/Face-Tattoo/Api_Labs/commits?author=VanAntonietti) and [Paulo](https://github.com/Yaten/Yaten)
Enjoyed the application? Please, consider contributing to the project.

## License

This project is under the [GNU General Public License v3](LICENSE).

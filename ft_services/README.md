# ft_services
This project is a introduction to cluster management and deployment with Kubernetes. Virtualiztion of a network and "clustering" will be used..


### Nginx container

Follow this nginx installation guide: https://wiki.alpinelinux.org/wiki/Nginx.  
If nginx can not start with rc-service, try these commands within the container:
```
openrc
touch /run/openrc/softlevel
```
If you do not need to interact with the container using a terminal, add `nginx -g 'daemon off;'` in your script.  
This will also serve to prevent the container from stopping.
You should be apple to connect to http://localhost and see __Server is online__ when the container is up.

### MySql container

Follow this installation guide: https://wiki.alpinelinux.org/wiki/MariaDB to setup mariadb (notice that rc script is used so you will need openrc package). You can skip the `mariadb-secure-installation`.
Then create the wordpress database:  
https://wordpress.org/support/article/creating-database-for-wordpress/#using-the-mysql-client.

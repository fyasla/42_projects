# ft_services
This project is a introduction to cluster management and deployment with Kubernetes. Virtualiztion of a network and "clustering" will be used..


### Nginx container

Follow this nginx installation guide on alpine linux:
https://wiki.alpinelinux.org/wiki/Nginx.  
If nginx can not start with rc-service, try these commands within the container:
```
openrc
touch /run/openrc/softlevel
```
If you do not need to interact with the container using a terminal, add `nginx -g 'daemon off;'` in your script.  
This will also serve to prevent the container from stopping.

#update mysql configuration
rm -rf /etc/my.conf.d /etc/my.conf
mv /srcs/my.cnf /etc/my.conf
mv /srcs/my.cnf.d /etc/my.cnf.D

#start mysql
openrc
touch /run/openrc/softlevel
# /etc/init.d/mariadb setup
# rc-service mariadb start
<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define('DB_NAME', 'wordpress');

/** MySQL database username */
define('DB_USER', 'wordpressuser');

/** MySQL database password */
define('DB_PASSWORD', 'password');

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

define('FS_METHOD', 'direct');

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'i@AOOS7Ep90AXC`2>W&2|RT~Fu2tugQks~|/of>0O mV&!KS(F&Z6/_DPK:h_lE!' );
define( 'SECURE_AUTH_KEY',  '/QQ7<Z6&xt09^8O< H>ZbFR82E|BI/z%I-S,HLCs5ce+OA .oviR@kN$vGCVc6i)' );
define( 'LOGGED_IN_KEY',    'F|+$ q1T7]eSmpHQG:S]|*y2A2bPt L;>w^:%JRzNQCc{BI?,,O+wTUR/3k/O)yQ' );
define( 'NONCE_KEY',        'AAX($acem(]B7Y_H=~OYP27ip=GtlBW*[W?|i|C]>XUZ~d@)9|<B#74WX-By65Tx' );
define( 'AUTH_SALT',        'zPc$qgIj+mi5_(@7QkFF.3|!z|m!-B+[wm37k;WK|oysAy/-jhnQZ)UV/@sd=g0e' );
define( 'SECURE_AUTH_SALT', 'V;Emz%d1H<jW)f88J3|2+,F{psX;7/USm?4KlZxGg(#(<-3rb:U/<rk/+p+kEI|N' );
define( 'LOGGED_IN_SALT',   'y4#JEW:[}aE4j*=yh6,e;7%6A[;|VC.udV)dVQ>P?6sF`o]-o=7gpKcW.Z;K^$I9' );
define( 'NONCE_SALT',       'tRnC-;V9+}gw9XR%--lsgB7wSdU8w:bd+d,*Iq0Fvj89xt!?v1-@r&b086g&CxcV' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
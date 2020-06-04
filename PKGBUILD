# Maintainer: alcubierre-drive
pkgname=scan_finger
pkgrel=6
pkgver=0.1
pkgdesc="xtrlock-pam patched with python-validity to use authentification with 138a:0097"
arch=('any')
#url="https://github.com/alcubierre-drive/backlight-tooler"
license=('GPL')
depends=('systemd' 'glibc')
makedepends=('gcc' 'make')
source=(scan_finger_src.tgz)
md5sums=('SKIP')

pkgver() {
    printf 0.1
}

prepare() {
    : Nothing
}

build() {
    : Nothing
}

check() {
    : Nothing
}

package() {
    tar xf scan_finger_src.tgz
    cd scan_finger_src
    PREFIX=$pkgdir ./install.sh
}

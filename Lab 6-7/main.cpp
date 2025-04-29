#include <console.h>
#include <tests.h>
using namespace std;
int main() {
    vector<Locatar> locatari;
    Valid valid;
    Repo repo(locatari);
    Service service(repo, valid);
    Console console(service);
    console.run();
    Tests::test();
    return 0;
}
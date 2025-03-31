#include <console.h>
using namespace std;
int main() {
    vector<Locatar> locatari;
    Valid valid;
    Repo repo(locatari);
    Service service(repo, valid);
    Console console(service);
    console.run();
    return 0;
}
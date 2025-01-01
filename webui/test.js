async function main() {
    while(1){
        await fetch("http://192.168.101.159/historyShort");
    }
}
main()
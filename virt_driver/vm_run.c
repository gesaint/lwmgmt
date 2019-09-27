








virDomainPtr dom;
const char *xmlconfig = "<domain>........</domain>";

dom = virConnectCreateXML(conn, xmlconfig, 0);

if (!dom) {
    fprintf(stderr, "Domain creation failed");
    return;
}

fprintf(stderr, "Guest %s has booted", virDomainName(dom));
virDomainFree(dom);


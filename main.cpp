#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>

using namespace xercesc;
using std::map;
using std::string;
using std::pair;
// main
int main(void)
{
	map<string,pair<int,int> > myData;

	// Initialize xerces
	try { XMLPlatformUtils::Initialize(); }
	catch (const XMLException& toCatch) {
		char* message = XMLString::transcode(toCatch.getMessage());
		std::cout << "Error during initialization! :\n" << message << "\n";
		XMLString::release(&message);
		return 1;
	}
	// Create parser, set parser values for validation
	XercesDOMParser* parser = new XercesDOMParser();
	parser->setValidationScheme(XercesDOMParser::Val_Always);
	parser->setDoNamespaces(true);
	parser->setDoSchema(true);
	parser->setValidationConstraintFatal(true);

	// You'll probably need to change the string below, or you'll get a segmentation fault:
	parser->parse(XMLString::transcode("TSPPConfig.xml"));

	DOMElement* docRootNode;
	DOMDocument* doc;
	DOMNodeIterator * walker;
	doc = parser->getDocument();
	docRootNode = doc->getDocumentElement();

	// Create the node iterator, that will walk through each element.
	walker = doc->createNodeIterator(docRootNode,DOMNodeFilter::SHOW_ELEMENT,NULL,true);
	// Some declarations
	DOMNode * current_node = NULL;
	string currentNodeName;
	string parentNodeName;
	for (current_node = walker->nextNode(); current_node != 0; current_node = walker->nextNode())
	{
		currentNodeName = XMLString::transcode(current_node->getNodeName());
		parentNodeName = XMLString::transcode(current_node->getParentNode()->getNodeName());
		std::cout << currentNodeName << ", son of " << parentNodeName << " Has value "
				<< XMLString::transcode(current_node->getFirstChild()->getNodeValue()) << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////
//
//  Create a link to SVN locations for specified sorce file/directory.
//  Works only in 'Source navigation' mode.
//

function SVNLocations()
{
    var url = document.URL;
    var pos = url.indexOf('CPP_DOC/lxr/source/');
    if (pos == -1) {
        return;
    }
    var pos1 = url.indexOf('http://intranet.ncbi.nlm.nih.gov');
    if (pos1 == -1) {
        pos1 = url.indexOf('/gui/');
        if (pos1 != -1) {
            return;
        }
    }
    document.write('<a id="svn-button" href="svn.cgi/' + escape(url.substr(pos+19)) + '"><b>SVN</b></a>');
}

#ifndef SCRIPT_SCRIPTAPI_H
#define SCRIPT_SCRIPTAPI_H

#define DSCRIPT_API 0.2
#include <string>
#include <fstream>

#define SubmitType_STRING 1
#define SubmitType_FILE 2
#define SubmitType_BOTHSTRINGANDFILE 3
#define SubmitType_FILENAME 4
#define SubmitType_BOTHSTRINGANDFILENAME 5
#define SubmitType_BOTHFILENAMEANDFILE 6
#define SubmitType_ALL 7

class ScriptAPI
{
public:
    /* Do whatever you need to do to start up. */
    virtual void initialize() = 0;
    /* Create language bindings for Disandria-to-scripting language */
    virtual void createBindings() = 0;
    /* How do you want to process scripts?
     * A) By submitting a string
     * B) By giving a filename
     * C) All of the above
     */
    virtual int scriptRequests() = 0;
    /* Should be obvious by their names */
    virtual void scriptByString(std::string&) = 0;
    virtual void scriptByFilename(std::string&) = 0;
    virtual void scriptByFile(std::ifstream&) = 0;
    /* Destroy any bindings (NOTHING ELSE, because reset() calls destroyBindings(), then createBindings(),
     * and still expects the system to be still useable)*/
    virtual void destroyBindings() = 0;
    /* Uninitialize the system. Assume nothing, clean up after yourself. */
    virtual void uninitialize() = 0;
    /* Default implementation calls destroyBindings(), then createBindings()
     * Override if you can reset the language better than that.
     * DO NOT IGNORE. When called, Disandria expects the language to be COMPLETELY reset.
     */
    virtual void reset();
};

#endif // SCRIPT_SCRIPTAPI_H

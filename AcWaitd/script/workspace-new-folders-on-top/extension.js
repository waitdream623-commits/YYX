'use strict';

const vscode = require('vscode');

function activate(context) {
    context.subscriptions.push(vscode.workspace.onDidChangeWorkspaceFolders(({ added }) => {
        if (added.length === 0) return;

        const setting = vscode.workspace.getConfiguration('workspaceNewFoldersOnTop').inspect('enabled');
        if (setting?.workspaceValue !== true) return;

        const folders = vscode.workspace.workspaceFolders ?? [];
        const addedUris = new Set(added.map(folder => folder.uri.toString()));
        const newFolders = folders.filter(folder => addedUris.has(folder.uri.toString()));
        const oldFolders = folders.filter(folder => !addedUris.has(folder.uri.toString()));
        const ordered = [...newFolders, ...oldFolders];

        if (ordered.every((folder, index) => folder === folders[index])) return;

        // Replace the ordering in one operation. A different first root can restart the extension host.
        const entries = ordered.map(({ uri, name }) => ({ uri, name }));
        vscode.workspace.updateWorkspaceFolders(0, folders.length, ...entries);
    }));
}

module.exports = { activate };

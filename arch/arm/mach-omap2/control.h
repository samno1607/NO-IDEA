  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Editing PK2-O3D/arch/arm/mach-omap2/control.h at master · samno1607/PK2-O3D</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon-precomposed" sizes="57x57" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="apple-touch-icon-114.png" />
    <link rel="apple-touch-icon-precomposed" sizes="72x72" href="apple-touch-icon-144.png" />
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="apple-touch-icon-144.png" />

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.png" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="QngfAcCIhWc/gkRPBHoFMy4TviKRTZRnI1IRoilUQK0=" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/assets/github-c53857461282b4a14a0e5fc2e1b495174fdb0a4c.css" media="screen" rel="stylesheet" type="text/css" />
    <link href="https://a248.e.akamai.net/assets.github.com/assets/github2-06bb6d88b09b280248a1f284fd6297fb7f56c4ce.css" media="screen" rel="stylesheet" type="text/css" />
    


    <script src="https://a248.e.akamai.net/assets.github.com/assets/frameworks-917510fd4e1e5f0487cfe32445a6cfc8927e84f1.js" type="text/javascript"></script>
    
    <script defer="defer" src="https://a248.e.akamai.net/assets.github.com/assets/github-a3e61f5b3e7c67bdef504c205abf5d8be6563d2f.js" type="text/javascript"></script>
    
    

        <meta property="og:title" content="PK2-O3D"/>
    <meta property="og:type" content="githubog:gitrepository"/>
    <meta property="og:url" content="https://github.com/samno1607/PK2-O3D"/>
    <meta property="og:image" content="https://a248.e.akamai.net/assets.github.com/images/gravatars/gravatar-140.png?1340935010"/>
    <meta property="og:site_name" content="GitHub"/>
    <meta property="og:description" content="Unofficial Promethius 2.0 Kernel. Contribute to PK2-O3D development by creating an account on GitHub."/>

    <meta name="description" content="Unofficial Promethius 2.0 Kernel. Contribute to PK2-O3D development by creating an account on GitHub." />

  <link href="https://github.com/samno1607/PK2-O3D/commits/master.atom" rel="alternate" title="Recent Commits to PK2-O3D:master" type="application/atom+xml" />

  </head>


  <body class="logged_in page-edit-blob linux vis-public env-production ">
    <div id="wrapper">

    
    

      <div id="header" class="true clearfix">
        <div class="container clearfix">
          <a class="site-logo" href="https://github.com/">
            <img alt="GitHub" class="github-logo-4x" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x.png?1340935010" />
            <img alt="GitHub" class="github-logo-4x-hover" height="30" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov7@4x-hover.png?1340935010" />
          </a>

              <a href="/notifications" class="notification-indicator tooltipped downwards" title="You have no unread notifications">
                <span class="mail-status all-read"></span>
              </a>

              
    <div class="topsearch ">
        <form accept-charset="UTF-8" action="/search" id="top_search_form" method="get">
  <a href="/search" class="advanced-search tooltipped downwards" title="Advanced Search"><span class="mini-icon mini-icon-advanced-search"></span></a>
  <div class="search placeholder-field js-placeholder-field">
    <input type="text" class="search my_repos_autocompleter" id="global-search-field" name="q" results="5" spellcheck="false" autocomplete="off" data-autocomplete="my-repos-autocomplete" placeholder="Search&hellip;" data-hotkey="s" />
    <div id="my-repos-autocomplete" class="autocomplete-results">
      <ul class="js-navigation-container"></ul>
    </div>
    <input type="submit" value="Search" class="button">
    <span class="mini-icon mini-icon-search-input"></span>
  </div>
  <input type="hidden" name="type" value="Everything" />
  <input type="hidden" name="repo" value="" />
  <input type="hidden" name="langOverride" value="" />
  <input type="hidden" name="start_value" value="1" />
</form>

      <ul class="top-nav">
          <li class="explore"><a href="https://github.com/explore">Explore</a></li>
          <li><a href="https://gist.github.com">Gist</a></li>
          <li><a href="/blog">Blog</a></li>
        <li><a href="http://help.github.com">Help</a></li>
      </ul>
    </div>


            


  <div id="userbox">
    <div id="user">
      <a href="https://github.com/samno1607"><img height="20" src="https://secure.gravatar.com/avatar/8cdc7bc6411b241ab5c501ce9ceaacf4?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="20" /></a>
      <a href="https://github.com/samno1607" class="name">samno1607</a>
    </div>
    <ul id="user-links">
      <li>
        <a href="/new" id="new_repo" class="tooltipped downwards" title="Create a New Repo"><span class="mini-icon mini-icon-create"></span></a>
      </li>
      <li>
        <a href="/settings/profile" id="account_settings"
          class="tooltipped downwards"
          title="Account Settings ">
          <span class="mini-icon mini-icon-account-settings"></span>
        </a>
      </li>
      <li>
          <a href="/logout" data-method="post" id="logout" class="tooltipped downwards" title="Sign Out">
            <span class="mini-icon mini-icon-logout"></span>
          </a>
      </li>
    </ul>
  </div>



          
        </div>
      </div>

      

      

            <div class="site hfeed" itemscope itemtype="http://schema.org/WebPage">
      <div class="container hentry">
        <div class="pagehead repohead instapaper_ignore readability-menu">
        <div class="title-actions-bar">
          



              <ul class="pagehead-actions">

          <li class="nspr">
            <a href="/samno1607/PK2-O3D/pull/new/master" class="minibutton btn-pull-request ">Pull Request</a>
          </li>

          <li class="subscription">
              <form accept-charset="UTF-8" action="/notifications/subscribe" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="QngfAcCIhWc/gkRPBHoFMy4TviKRTZRnI1IRoilUQK0=" /></div>
  <input id="repository_id" name="repository_id" type="hidden" value="5415605" />
  <div class="context-menu-container js-menu-container js-context-menu">
    <span class="minibutton switcher bigger js-menu-target">
      <span class="js-context-button">
          <span class="mini-icon mini-icon-unwatch"></span> Unwatch
      </span>
    </span>

    <div class="context-pane js-menu-content">
      <a href="javascript:;" class="close js-menu-close"><span class="mini-icon mini-icon-remove-close"></span></a>
      <div class="context-title">Notification status</div>

      <div class="context-body pane-selector">
        <ul class="js-navigation-container">
          <li class="selector-item js-navigation-item js-navigation-target ">
            <span class="mini-icon mini-icon-confirm"></span>
            <label>
              <input id="do_included" name="do" type="radio" value="included" />
              <h4>Not watching</h4>
              <p>You will only receive notifications when you participate or are mentioned.</p>
            </label>
            <span class="context-button-text js-context-button-text">
              <span class="mini-icon mini-icon-watching"></span>
              Watch
            </span>
          </li>
          <li class="selector-item js-navigation-item js-navigation-target selected">
            <span class="mini-icon mini-icon-confirm"></span>
            <label>
              <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
              <h4>Watching</h4>
              <p>You will receive all notifications for this repository.</p>
            </label>
            <span class="context-button-text js-context-button-text">
              <span class="mini-icon mini-icon-unwatch"></span>
              Unwatch
            </span>
          </li>
          <li class="selector-item js-navigation-item js-navigation-target ">
            <span class="mini-icon mini-icon-confirm"></span>
            <label>
              <input id="do_ignore" name="do" type="radio" value="ignore" />
              <h4>Ignored</h4>
              <p>You will not receive notifications for this repository.</p>
            </label>
            <span class="context-button-text js-context-button-text">
              <span class="mini-icon mini-icon-mute"></span>
              Stop ignoring
            </span>
          </li>
        </ul>
      </div>
    </div>
  </div>
</form>
          </li>

          <li class="js-toggler-container js-social-container starring-container ">
            <a href="/samno1607/PK2-O3D/unstar" class="minibutton js-toggler-target starred" data-remote="true" data-method="post" rel="nofollow">
              <span class="mini-icon mini-icon-star"></span>
                Unstar
            </a>
            <a href="/samno1607/PK2-O3D/star" class="minibutton js-toggler-target unstarred" data-remote="true" data-method="post" rel="nofollow">
              <span class="mini-icon mini-icon-star"></span>
                Star
            </a><a class="social-count js-social-count" href="/samno1607/PK2-O3D/stargazers">0</a>
          </li>

              <li><a href="/samno1607/PK2-O3D/fork" class="minibutton btn-fork js-toggler-target fork-button lighter" rel="nofollow" data-method="post">Fork</a><a href="/samno1607/PK2-O3D/network" class="social-count">0</a>
              </li>


    </ul>

          <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
            <span class="repo-label"><span>public</span></span>
            <span class="mega-icon mega-icon-public-repo"></span>
            <span class="author vcard">
<a href="/samno1607" class="url fn" itemprop="url" rel="author">              <span itemprop="title">samno1607</span>
              </a></span> /
            <strong><a href="/samno1607/PK2-O3D" class="js-current-repository">PK2-O3D</a></strong>
          </h1>
        </div>

          

  <ul class="tabs">
    <li><a href="/samno1607/PK2-O3D" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/samno1607/PK2-O3D/network" highlight="repo_network">Network</a>
    <li><a href="/samno1607/PK2-O3D/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/samno1607/PK2-O3D/issues" highlight="repo_issues">Issues <span class='counter'>0</span></a></li>

      <li><a href="/samno1607/PK2-O3D/wiki" highlight="repo_wiki">Wiki</a></li>

    <li><a href="/samno1607/PK2-O3D/graphs" highlight="repo_graphsrepo_contributors">Graphs</a></li>

      <li>
        <a href="/samno1607/PK2-O3D/admin">Admin</a>
      </li>

  </ul>
  
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/samno1607/PK2-O3D/tree-list/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d"
      data-blob-url-prefix="/samno1607/PK2-O3D/blob/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d"
    >

  <div class="breadcrumb">
    <span class="bold"><a href="/samno1607/PK2-O3D">PK2-O3D</a></span> /
    <input class="tree-finder-input js-navigation-enable" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/samno1607/PK2-O3D/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever" rel="nofollow">Dismiss</a>
        <span class="bold">Octotip:</span> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list js-navigation-container">
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form accept-charset="UTF-8">
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        Go
      </button>
    </div>
  </form>
</div>


<div class="tabnav">

  <span class="tabnav-right">
    <ul class="tabnav-tabs">
      <li><a href="/samno1607/PK2-O3D/tags" class="tabnav-tab" highlight="repo_tags">Tags <span class="counter blank">0</span></a></li>
      <li><a href="/samno1607/PK2-O3D/downloads" class="tabnav-tab" highlight="repo_downloads">Downloads <span class="counter blank">0</span></a></li>
    </ul>
    
  </span>

  <div class="tabnav-widget scope">

    <div class="context-menu-container js-menu-container js-context-menu">
      <a href="#"
         class="minibutton bigger switcher js-menu-target js-commitish-button btn-branch repo-tree"
         data-hotkey="w"
         data-master-branch="master"
         data-ref="master">
         <span><i>branch:</i> master</span>
      </a>

      <div class="context-pane commitish-context js-menu-content">
        <a href="javascript:;" class="close js-menu-close"><span class="mini-icon mini-icon-remove-close"></span></a>
        <div class="context-title">Switch branches/tags</div>
        <div class="context-body pane-selector commitish-selector js-navigation-container">
          <div class="filterbar">
            <input type="text" id="context-commitish-filter-field" class="js-navigation-enable" placeholder="Filter branches/tags" data-filterable />
            <ul class="tabs">
              <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
              <li><a href="#" data-filter="tags">Tags</a></li>
            </ul>
          </div>

          <div class="js-filter-tab js-filter-branches" data-filterable-for="context-commitish-filter-field" data-filterable-type=substring>
            <div class="no-results js-not-filterable">Nothing to show</div>
              <div class="commitish-item branch-commitish selector-item js-navigation-item js-navigation-target selected">
                <span class="mini-icon mini-icon-confirm"></span>
                <h4>
                    <a href="/samno1607/PK2-O3D/edit/master/arch/arm/mach-omap2/control.h" class="js-navigation-open" data-name="master" rel="nofollow">master</a>
                </h4>
              </div>
          </div>

          <div class="js-filter-tab js-filter-tags" style="display:none" data-filterable-for="context-commitish-filter-field" data-filterable-type=substring>
            <div class="no-results js-not-filterable">Nothing to show</div>
          </div>
        </div>
      </div><!-- /.commitish-context-context -->
    </div>
  </div> <!-- /.scope -->

  <ul class="tabnav-tabs">
    <li><a href="/samno1607/PK2-O3D" class="selected tabnav-tab" highlight="repo_source">Files</a></li>
    <li><a href="/samno1607/PK2-O3D/commits/master" class="tabnav-tab" highlight="repo_commits">Commits</a></li>
    <li><a href="/samno1607/PK2-O3D/branches" class="tabnav-tab" highlight="repo_branches" rel="nofollow">Branches <span class="counter ">1</span></a></li>
  </ul>

</div>

  
  
  


          

        </div><!-- /.repohead -->

        <div id="js-repo-pjax-container" data-pjax-container>
          




<ul class="big-actions">
  <li><a class="minibutton" href="/samno1607/PK2-O3D/blob/master/arch/arm/mach-omap2/control.h">Back to source view</a></li>
</ul>

<div class="breadcrumb" data-path="arch/arm/mach-omap2/control.h/">
  <b itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d" class="js-rewrite-sha" itemprop="url"><span itemprop="title">PK2-O3D</span></a></b> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch" class="js-rewrite-sha" itemscope="url"><span itemprop="title">arch</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch/arm" class="js-rewrite-sha" itemscope="url"><span itemprop="title">arm</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch/arm/mach-omap2" class="js-rewrite-sha" itemscope="url"><span itemprop="title">mach-omap2</span></a></span> / <strong class="final-path">control.h</strong> <span class="js-clippy mini-icon mini-icon-clippy " data-clipboard-text="arch/arm/mach-omap2/control.h" data-copied-hint="copied!" data-copy-hint="copy to clipboard"></span>
</div>

  <div id="files">
    
<div class="js-blob-edit-progress large-loading-area">
  <img alt="Octocat-spinner-64" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-64.gif?1340935010" />
</div>

<form accept-charset="UTF-8" action="/samno1607/PK2-O3D/tree-save/master/arch/arm/mach-omap2/control.h" class="js-blob-edit-form" method="post" style="display:none"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="QngfAcCIhWc/gkRPBHoFMy4TviKRTZRnI1IRoilUQK0=" /></div>  <input id="utc_offset" type="hidden" name="utc_offset">
  <div class="file">
    <div class="meta">
      <div class="info">
        <span class="icon"><span class="mini-icon mini-icon-text-file"></span></span>
      </div><!-- /.info -->


      <ul class="edit-preview-tabs js-blob-edit-actions">
        <li><a href="#" class="code selected">Code</a></li>
        <li><a href="#" class="preview">Preview</a></li>
      </ul>

      <ul class="actions">
        <li>
          <select id="indent-mode">
            <optgroup label="Indent Mode">
              <option value="tabs">Tabs</option>
              <option value="spaces">Spaces</option>
            </optgroup>
          </select>
        </li>

        <li>
          <select id="indent-width">
            <optgroup label="Indent Size">
              <option value="2">2</option>
              <option value="4">4</option>
              <option value="8">8</option>
            </optgroup>
          </select>
        </li>

        <li>
          <select id="wrap-mode">
            <optgroup label="Line Wrap Mode">
              <option value="off">No wrap</option>
              <option value="on">Soft wrap</option>
            </optgroup>
          </select>
        </li>
      </ul>
    </div><!-- /.meta -->

    <input type="hidden" name="commit" value="b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d">

    <div class="js-commit-create">
      <textarea class="file-editor-textarea" rows="35" name="value" data-language="C" data-filename="control.h" autofocus>/*
 * arch/arm/mach-omap2/control.h
 *
 * OMAP2/3/4 System Control Module definitions
 *
 * Copyright (C) 2007-2010 Texas Instruments, Inc.
 * Copyright (C) 2007-2008, 2010 Nokia Corporation
 *
 * Written by Paul Walmsley
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_CONTROL_H
#define __ARCH_ARM_MACH_OMAP2_CONTROL_H

#include &lt;mach/io.h&gt;
#include &lt;mach/ctrl_module_core_44xx.h&gt;
#include &lt;mach/ctrl_module_wkup_44xx.h&gt;
#include &lt;mach/ctrl_module_pad_core_44xx.h&gt;
#include &lt;mach/ctrl_module_pad_wkup_44xx.h&gt;

#ifndef __ASSEMBLY__
#define OMAP242X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP242X_CTRL_BASE + (reg))
#define OMAP243X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP243X_CTRL_BASE + (reg))
#define OMAP343X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP343X_CTRL_BASE + (reg))
#else
#define OMAP242X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP242X_CTRL_BASE + (reg))
#define OMAP243X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP243X_CTRL_BASE + (reg))
#define OMAP343X_CTRL_REGADDR(reg)					\
		OMAP2_L4_IO_ADDRESS(OMAP343X_CTRL_BASE + (reg))
#endif /* __ASSEMBLY__ */

/*
 * As elsewhere, the &quot;OMAP2_&quot; prefix indicates that the macro is valid for
 * OMAP24XX and OMAP34XX.
 */

/* Control submodule offsets */

#define OMAP2_CONTROL_INTERFACE		0x000
#define OMAP2_CONTROL_PADCONFS		0x030
#define OMAP2_CONTROL_GENERAL		0x270
#define OMAP343X_CONTROL_MEM_WKUP	0x600
#define OMAP343X_CONTROL_PADCONFS_WKUP	0xa00
#define OMAP343X_CONTROL_GENERAL_WKUP	0xa60

/* Control register offsets - read/write with omap_ctrl_{read,write}{bwl}() */

#define OMAP2_CONTROL_SYSCONFIG		(OMAP2_CONTROL_INTERFACE + 0x10)

/* CONTROL_GENERAL register offsets common to OMAP2 &amp; 3 */
#define OMAP2_CONTROL_DEVCONF0		(OMAP2_CONTROL_GENERAL + 0x0004)
#define OMAP2_CONTROL_MSUSPENDMUX_0	(OMAP2_CONTROL_GENERAL + 0x0020)
#define OMAP2_CONTROL_MSUSPENDMUX_1	(OMAP2_CONTROL_GENERAL + 0x0024)
#define OMAP2_CONTROL_MSUSPENDMUX_2	(OMAP2_CONTROL_GENERAL + 0x0028)
#define OMAP2_CONTROL_MSUSPENDMUX_3	(OMAP2_CONTROL_GENERAL + 0x002c)
#define OMAP2_CONTROL_MSUSPENDMUX_4	(OMAP2_CONTROL_GENERAL + 0x0030)
#define OMAP2_CONTROL_MSUSPENDMUX_5	(OMAP2_CONTROL_GENERAL + 0x0034)
#define OMAP2_CONTROL_SEC_CTRL		(OMAP2_CONTROL_GENERAL + 0x0040)
#define OMAP2_CONTROL_RPUB_KEY_H_0	(OMAP2_CONTROL_GENERAL + 0x0090)
#define OMAP2_CONTROL_RPUB_KEY_H_1	(OMAP2_CONTROL_GENERAL + 0x0094)
#define OMAP2_CONTROL_RPUB_KEY_H_2	(OMAP2_CONTROL_GENERAL + 0x0098)
#define OMAP2_CONTROL_RPUB_KEY_H_3	(OMAP2_CONTROL_GENERAL + 0x009c)

/* 242x-only CONTROL_GENERAL register offsets */
#define OMAP242X_CONTROL_DEVCONF	OMAP2_CONTROL_DEVCONF0 /* match TRM */
#define OMAP242X_CONTROL_OCM_RAM_PERM	(OMAP2_CONTROL_GENERAL + 0x0068)

/* 243x-only CONTROL_GENERAL register offsets */
/* CONTROL_IVA2_BOOT{ADDR,MOD} are at the same place on 343x - noted below */
#define OMAP243X_CONTROL_DEVCONF1	(OMAP2_CONTROL_GENERAL + 0x0078)
#define OMAP243X_CONTROL_CSIRXFE	(OMAP2_CONTROL_GENERAL + 0x007c)
#define OMAP243X_CONTROL_IVA2_BOOTADDR	(OMAP2_CONTROL_GENERAL + 0x0190)
#define OMAP243X_CONTROL_IVA2_BOOTMOD	(OMAP2_CONTROL_GENERAL + 0x0194)
#define OMAP243X_CONTROL_IVA2_GEMCFG	(OMAP2_CONTROL_GENERAL + 0x0198)
#define OMAP243X_CONTROL_PBIAS_LITE	(OMAP2_CONTROL_GENERAL + 0x0230)

/* 24xx-only CONTROL_GENERAL register offsets */
#define OMAP24XX_CONTROL_DEBOBS		(OMAP2_CONTROL_GENERAL + 0x0000)
#define OMAP24XX_CONTROL_EMU_SUPPORT	(OMAP2_CONTROL_GENERAL + 0x0008)
#define OMAP24XX_CONTROL_SEC_TEST	(OMAP2_CONTROL_GENERAL + 0x0044)
#define OMAP24XX_CONTROL_PSA_CTRL	(OMAP2_CONTROL_GENERAL + 0x0048)
#define OMAP24XX_CONTROL_PSA_CMD	(OMAP2_CONTROL_GENERAL + 0x004c)
#define OMAP24XX_CONTROL_PSA_VALUE	(OMAP2_CONTROL_GENERAL + 0x0050)
#define OMAP24XX_CONTROL_SEC_EMU	(OMAP2_CONTROL_GENERAL + 0x0060)
#define OMAP24XX_CONTROL_SEC_TAP	(OMAP2_CONTROL_GENERAL + 0x0064)
#define OMAP24XX_CONTROL_OCM_PUB_RAM_ADD	(OMAP2_CONTROL_GENERAL + 0x006c)
#define OMAP24XX_CONTROL_EXT_SEC_RAM_START_ADD	(OMAP2_CONTROL_GENERAL + 0x0070)
#define OMAP24XX_CONTROL_EXT_SEC_RAM_STOP_ADD	(OMAP2_CONTROL_GENERAL + 0x0074)
#define OMAP24XX_CONTROL_SEC_STATUS		(OMAP2_CONTROL_GENERAL + 0x0080)
#define OMAP24XX_CONTROL_SEC_ERR_STATUS		(OMAP2_CONTROL_GENERAL + 0x0084)
#define OMAP24XX_CONTROL_STATUS			(OMAP2_CONTROL_GENERAL + 0x0088)
#define OMAP24XX_CONTROL_GENERAL_PURPOSE_STATUS	(OMAP2_CONTROL_GENERAL + 0x008c)
#define OMAP24XX_CONTROL_RAND_KEY_0	(OMAP2_CONTROL_GENERAL + 0x00a0)
#define OMAP24XX_CONTROL_RAND_KEY_1	(OMAP2_CONTROL_GENERAL + 0x00a4)
#define OMAP24XX_CONTROL_RAND_KEY_2	(OMAP2_CONTROL_GENERAL + 0x00a8)
#define OMAP24XX_CONTROL_RAND_KEY_3	(OMAP2_CONTROL_GENERAL + 0x00ac)
#define OMAP24XX_CONTROL_CUST_KEY_0	(OMAP2_CONTROL_GENERAL + 0x00b0)
#define OMAP24XX_CONTROL_CUST_KEY_1	(OMAP2_CONTROL_GENERAL + 0x00b4)
#define OMAP24XX_CONTROL_TEST_KEY_0	(OMAP2_CONTROL_GENERAL + 0x00c0)
#define OMAP24XX_CONTROL_TEST_KEY_1	(OMAP2_CONTROL_GENERAL + 0x00c4)
#define OMAP24XX_CONTROL_TEST_KEY_2	(OMAP2_CONTROL_GENERAL + 0x00c8)
#define OMAP24XX_CONTROL_TEST_KEY_3	(OMAP2_CONTROL_GENERAL + 0x00cc)
#define OMAP24XX_CONTROL_TEST_KEY_4	(OMAP2_CONTROL_GENERAL + 0x00d0)
#define OMAP24XX_CONTROL_TEST_KEY_5	(OMAP2_CONTROL_GENERAL + 0x00d4)
#define OMAP24XX_CONTROL_TEST_KEY_6	(OMAP2_CONTROL_GENERAL + 0x00d8)
#define OMAP24XX_CONTROL_TEST_KEY_7	(OMAP2_CONTROL_GENERAL + 0x00dc)
#define OMAP24XX_CONTROL_TEST_KEY_8	(OMAP2_CONTROL_GENERAL + 0x00e0)
#define OMAP24XX_CONTROL_TEST_KEY_9	(OMAP2_CONTROL_GENERAL + 0x00e4)

#define OMAP343X_CONTROL_PADCONF_SYSNIRQ (OMAP2_CONTROL_INTERFACE + 0x01b0)

/* 34xx-only CONTROL_GENERAL register offsets */
#define OMAP343X_CONTROL_PADCONF_OFF	(OMAP2_CONTROL_GENERAL + 0x0000)
#define OMAP343X_CONTROL_MEM_DFTRW0	(OMAP2_CONTROL_GENERAL + 0x0008)
#define OMAP343X_CONTROL_MEM_DFTRW1	(OMAP2_CONTROL_GENERAL + 0x000c)
#define OMAP343X_CONTROL_DEVCONF1	(OMAP2_CONTROL_GENERAL + 0x0068)
#define OMAP343X_CONTROL_CSIRXFE		(OMAP2_CONTROL_GENERAL + 0x006c)
#define OMAP343X_CONTROL_SEC_STATUS		(OMAP2_CONTROL_GENERAL + 0x0070)
#define OMAP343X_CONTROL_SEC_ERR_STATUS		(OMAP2_CONTROL_GENERAL + 0x0074)
#define OMAP343X_CONTROL_SEC_ERR_STATUS_DEBUG	(OMAP2_CONTROL_GENERAL + 0x0078)
#define OMAP343X_CONTROL_STATUS			(OMAP2_CONTROL_GENERAL + 0x0080)
#define OMAP343X_CONTROL_GENERAL_PURPOSE_STATUS	(OMAP2_CONTROL_GENERAL + 0x0084)
#define OMAP343X_CONTROL_RPUB_KEY_H_4	(OMAP2_CONTROL_GENERAL + 0x00a0)
#define OMAP343X_CONTROL_RAND_KEY_0	(OMAP2_CONTROL_GENERAL + 0x00a8)
#define OMAP343X_CONTROL_RAND_KEY_1	(OMAP2_CONTROL_GENERAL + 0x00ac)
#define OMAP343X_CONTROL_RAND_KEY_2	(OMAP2_CONTROL_GENERAL + 0x00b0)
#define OMAP343X_CONTROL_RAND_KEY_3	(OMAP2_CONTROL_GENERAL + 0x00b4)
#define OMAP343X_CONTROL_TEST_KEY_0	(OMAP2_CONTROL_GENERAL + 0x00c8)
#define OMAP343X_CONTROL_TEST_KEY_1	(OMAP2_CONTROL_GENERAL + 0x00cc)
#define OMAP343X_CONTROL_TEST_KEY_2	(OMAP2_CONTROL_GENERAL + 0x00d0)
#define OMAP343X_CONTROL_TEST_KEY_3	(OMAP2_CONTROL_GENERAL + 0x00d4)
#define OMAP343X_CONTROL_TEST_KEY_4	(OMAP2_CONTROL_GENERAL + 0x00d8)
#define OMAP343X_CONTROL_TEST_KEY_5	(OMAP2_CONTROL_GENERAL + 0x00dc)
#define OMAP343X_CONTROL_TEST_KEY_6	(OMAP2_CONTROL_GENERAL + 0x00e0)
#define OMAP343X_CONTROL_TEST_KEY_7	(OMAP2_CONTROL_GENERAL + 0x00e4)
#define OMAP343X_CONTROL_TEST_KEY_8	(OMAP2_CONTROL_GENERAL + 0x00e8)
#define OMAP343X_CONTROL_TEST_KEY_9	(OMAP2_CONTROL_GENERAL + 0x00ec)
#define OMAP343X_CONTROL_TEST_KEY_10	(OMAP2_CONTROL_GENERAL + 0x00f0)
#define OMAP343X_CONTROL_TEST_KEY_11	(OMAP2_CONTROL_GENERAL + 0x00f4)
#define OMAP343X_CONTROL_TEST_KEY_12	(OMAP2_CONTROL_GENERAL + 0x00f8)
#define OMAP343X_CONTROL_TEST_KEY_13	(OMAP2_CONTROL_GENERAL + 0x00fc)
#define OMAP343X_CONTROL_IVA2_BOOTADDR	(OMAP2_CONTROL_GENERAL + 0x0190)
#define OMAP343X_CONTROL_IVA2_BOOTMOD	(OMAP2_CONTROL_GENERAL + 0x0194)
#define OMAP343X_CONTROL_DEBOBS(i)	(OMAP2_CONTROL_GENERAL + 0x01B0 \
					+ ((i) &gt;&gt; 1) * 4 + (!((i) &amp; 1)) * 2)
#define OMAP343X_CONTROL_PROG_IO0	(OMAP2_CONTROL_GENERAL + 0x01D4)
#define OMAP343X_CONTROL_PROG_IO1	(OMAP2_CONTROL_GENERAL + 0x01D8)
#define OMAP343X_CONTROL_DSS_DPLL_SPREADING	(OMAP2_CONTROL_GENERAL + 0x01E0)
#define OMAP343X_CONTROL_CORE_DPLL_SPREADING	(OMAP2_CONTROL_GENERAL + 0x01E4)
#define OMAP343X_CONTROL_PER_DPLL_SPREADING	(OMAP2_CONTROL_GENERAL + 0x01E8)
#define OMAP343X_CONTROL_USBHOST_DPLL_SPREADING	(OMAP2_CONTROL_GENERAL + 0x01EC)
#define OMAP343X_CONTROL_PBIAS_LITE	(OMAP2_CONTROL_GENERAL + 0x02B0)
#define OMAP343X_CONTROL_TEMP_SENSOR	(OMAP2_CONTROL_GENERAL + 0x02B4)
#define OMAP343X_CONTROL_SRAMLDO4	(OMAP2_CONTROL_GENERAL + 0x02B8)
#define OMAP343X_CONTROL_SRAMLDO5	(OMAP2_CONTROL_GENERAL + 0x02C0)
#define OMAP343X_CONTROL_CSI		(OMAP2_CONTROL_GENERAL + 0x02C4)

/* AM35XX only CONTROL_GENERAL register offsets */
#define AM35XX_CONTROL_MSUSPENDMUX_6    (OMAP2_CONTROL_GENERAL + 0x0038)
#define AM35XX_CONTROL_DEVCONF2         (OMAP2_CONTROL_GENERAL + 0x0310)
#define AM35XX_CONTROL_DEVCONF3         (OMAP2_CONTROL_GENERAL + 0x0314)
#define AM35XX_CONTROL_CBA_PRIORITY     (OMAP2_CONTROL_GENERAL + 0x0320)
#define AM35XX_CONTROL_LVL_INTR_CLEAR   (OMAP2_CONTROL_GENERAL + 0x0324)
#define AM35XX_CONTROL_IP_SW_RESET      (OMAP2_CONTROL_GENERAL + 0x0328)
#define AM35XX_CONTROL_IPSS_CLK_CTRL    (OMAP2_CONTROL_GENERAL + 0x032C)

/* 34xx PADCONF register offsets */
#define OMAP343X_PADCONF_ETK(i)		(OMAP2_CONTROL_PADCONFS + 0x5a8 + \
						(i)*2)
#define OMAP343X_PADCONF_ETK_CLK	OMAP343X_PADCONF_ETK(0)
#define OMAP343X_PADCONF_ETK_CTL	OMAP343X_PADCONF_ETK(1)
#define OMAP343X_PADCONF_ETK_D0		OMAP343X_PADCONF_ETK(2)
#define OMAP343X_PADCONF_ETK_D1		OMAP343X_PADCONF_ETK(3)
#define OMAP343X_PADCONF_ETK_D2		OMAP343X_PADCONF_ETK(4)
#define OMAP343X_PADCONF_ETK_D3		OMAP343X_PADCONF_ETK(5)
#define OMAP343X_PADCONF_ETK_D4		OMAP343X_PADCONF_ETK(6)
#define OMAP343X_PADCONF_ETK_D5		OMAP343X_PADCONF_ETK(7)
#define OMAP343X_PADCONF_ETK_D6		OMAP343X_PADCONF_ETK(8)
#define OMAP343X_PADCONF_ETK_D7		OMAP343X_PADCONF_ETK(9)
#define OMAP343X_PADCONF_ETK_D8		OMAP343X_PADCONF_ETK(10)
#define OMAP343X_PADCONF_ETK_D9		OMAP343X_PADCONF_ETK(11)
#define OMAP343X_PADCONF_ETK_D10	OMAP343X_PADCONF_ETK(12)
#define OMAP343X_PADCONF_ETK_D11	OMAP343X_PADCONF_ETK(13)
#define OMAP343X_PADCONF_ETK_D12	OMAP343X_PADCONF_ETK(14)
#define OMAP343X_PADCONF_ETK_D13	OMAP343X_PADCONF_ETK(15)
#define OMAP343X_PADCONF_ETK_D14	OMAP343X_PADCONF_ETK(16)
#define OMAP343X_PADCONF_ETK_D15	OMAP343X_PADCONF_ETK(17)

/* 34xx GENERAL_WKUP regist offsets */
#define OMAP343X_CONTROL_WKUP_DEBOBSMUX(i) (OMAP343X_CONTROL_GENERAL_WKUP + \
						0x008 + (i))
#define OMAP343X_CONTROL_WKUP_DEBOBS0 (OMAP343X_CONTROL_GENERAL_WKUP + 0x008)
#define OMAP343X_CONTROL_WKUP_DEBOBS1 (OMAP343X_CONTROL_GENERAL_WKUP + 0x00C)
#define OMAP343X_CONTROL_WKUP_DEBOBS2 (OMAP343X_CONTROL_GENERAL_WKUP + 0x010)
#define OMAP343X_CONTROL_WKUP_DEBOBS3 (OMAP343X_CONTROL_GENERAL_WKUP + 0x014)
#define OMAP343X_CONTROL_WKUP_DEBOBS4 (OMAP343X_CONTROL_GENERAL_WKUP + 0x018)

/* 34xx D2D idle-related pins, handled by PM core */
#define OMAP3_PADCONF_SAD2D_MSTANDBY   0x250
#define OMAP3_PADCONF_SAD2D_IDLEACK    0x254

/*
 * REVISIT: This list of registers is not comprehensive - there are more
 * that should be added.
 */

/*
 * Control module register bit defines - these should eventually go into
 * their own regbits file.  Some of these will be complicated, depending
 * on the device type (general-purpose, emulator, test, secure, bad, other)
 * and the security mode (secure, non-secure, don't care)
 */
/* CONTROL_DEVCONF0 bits */
#define OMAP2_MMCSDIO1ADPCLKISEL	(1 &lt;&lt; 24) /* MMC1 loop back clock */
#define OMAP24XX_USBSTANDBYCTRL		(1 &lt;&lt; 15)
#define OMAP2_MCBSP2_CLKS_MASK		(1 &lt;&lt; 6)
#define OMAP2_MCBSP1_FSR_MASK		(1 &lt;&lt; 4)
#define OMAP2_MCBSP1_CLKR_MASK		(1 &lt;&lt; 3)
#define OMAP2_MCBSP1_CLKS_MASK		(1 &lt;&lt; 2)

/* CONTROL_DEVCONF1 bits */
#define OMAP243X_MMC1_ACTIVE_OVERWRITE	(1 &lt;&lt; 31)
#define OMAP2_MMCSDIO2ADPCLKISEL	(1 &lt;&lt; 6) /* MMC2 loop back clock */
#define OMAP2_MCBSP5_CLKS_MASK		(1 &lt;&lt; 4) /* &gt; 242x */
#define OMAP2_MCBSP4_CLKS_MASK		(1 &lt;&lt; 2) /* &gt; 242x */
#define OMAP2_MCBSP3_CLKS_MASK		(1 &lt;&lt; 0) /* &gt; 242x */

/* CONTROL_STATUS bits */
#define OMAP2_DEVICETYPE_MASK		(0x7 &lt;&lt; 8)
#define OMAP2_SYSBOOT_5_MASK		(1 &lt;&lt; 5)
#define OMAP2_SYSBOOT_4_MASK		(1 &lt;&lt; 4)
#define OMAP2_SYSBOOT_3_MASK		(1 &lt;&lt; 3)
#define OMAP2_SYSBOOT_2_MASK		(1 &lt;&lt; 2)
#define OMAP2_SYSBOOT_1_MASK		(1 &lt;&lt; 1)
#define OMAP2_SYSBOOT_0_MASK		(1 &lt;&lt; 0)

/* CONTROL_PBIAS_LITE bits */
#define OMAP343X_PBIASLITESUPPLY_HIGH1	(1 &lt;&lt; 15)
#define OMAP343X_PBIASLITEVMODEERROR1	(1 &lt;&lt; 11)
#define OMAP343X_PBIASSPEEDCTRL1	(1 &lt;&lt; 10)
#define OMAP343X_PBIASLITEPWRDNZ1	(1 &lt;&lt; 9)
#define OMAP343X_PBIASLITEVMODE1	(1 &lt;&lt; 8)
#define OMAP343X_PBIASLITESUPPLY_HIGH0	(1 &lt;&lt; 7)
#define OMAP343X_PBIASLITEVMODEERROR0	(1 &lt;&lt; 3)
#define OMAP2_PBIASSPEEDCTRL0		(1 &lt;&lt; 2)
#define OMAP2_PBIASLITEPWRDNZ0		(1 &lt;&lt; 1)
#define OMAP2_PBIASLITEVMODE0		(1 &lt;&lt; 0)

/* CONTROL_PROG_IO1 bits */
#define OMAP3630_PRG_SDMMC1_SPEEDCTRL	(1 &lt;&lt; 20)

/* CONTROL_IVA2_BOOTMOD bits */
#define OMAP3_IVA2_BOOTMOD_SHIFT	0
#define OMAP3_IVA2_BOOTMOD_MASK		(0xf &lt;&lt; 0)
#define OMAP3_IVA2_BOOTMOD_IDLE		(0x1 &lt;&lt; 0)

/* CONTROL_PADCONF_X bits */
#define OMAP3_PADCONF_WAKEUPEVENT0	(1 &lt;&lt; 15)
#define OMAP3_PADCONF_WAKEUPENABLE0	(1 &lt;&lt; 14)

#define OMAP343X_SCRATCHPAD_ROM		(OMAP343X_CTRL_BASE + 0x860)
#define OMAP343X_SCRATCHPAD		(OMAP343X_CTRL_BASE + 0x910)
#define OMAP343X_SCRATCHPAD_ROM_OFFSET	0x19C

/* AM35XX_CONTROL_IPSS_CLK_CTRL bits */
#define AM35XX_USBOTG_VBUSP_CLK_SHIFT   0
#define AM35XX_CPGMAC_VBUSP_CLK_SHIFT   1
#define AM35XX_VPFE_VBUSP_CLK_SHIFT     2
#define AM35XX_HECC_VBUSP_CLK_SHIFT     3
#define AM35XX_USBOTG_FCLK_SHIFT        8
#define AM35XX_CPGMAC_FCLK_SHIFT        9
#define AM35XX_VPFE_FCLK_SHIFT          10

/*AM35XX CONTROL_LVL_INTR_CLEAR bits*/
#define AM35XX_CPGMAC_C0_MISC_PULSE_CLR	BIT(0)
#define AM35XX_CPGMAC_C0_RX_PULSE_CLR	BIT(1)
#define AM35XX_CPGMAC_C0_RX_THRESH_CLR	BIT(2)
#define AM35XX_CPGMAC_C0_TX_PULSE_CLR	BIT(3)
#define AM35XX_USBOTGSS_INT_CLR		BIT(4)
#define AM35XX_VPFE_CCDC_VD0_INT_CLR	BIT(5)
#define AM35XX_VPFE_CCDC_VD1_INT_CLR	BIT(6)
#define AM35XX_VPFE_CCDC_VD2_INT_CLR	BIT(7)

/*AM35XX CONTROL_IP_SW_RESET bits*/
#define AM35XX_USBOTGSS_SW_RST		BIT(0)
#define AM35XX_CPGMACSS_SW_RST		BIT(1)
#define AM35XX_VPFE_VBUSP_SW_RST	BIT(2)
#define AM35XX_HECC_SW_RST		BIT(3)
#define AM35XX_VPFE_PCLK_SW_RST		BIT(4)

/*
 * CONTROL OMAP STATUS register to identify OMAP3 features
 */
#define OMAP3_CONTROL_OMAP_STATUS	0x044c

#define OMAP3_SGX_SHIFT			13
#define OMAP3_SGX_MASK			(3 &lt;&lt; OMAP3_SGX_SHIFT)
#define		FEAT_SGX_FULL		0
#define		FEAT_SGX_HALF		1
#define		FEAT_SGX_NONE		2

#define OMAP3_IVA_SHIFT			12
#define OMAP3_IVA_MASK			(1 &lt;&lt; OMAP3_SGX_SHIFT)
#define		FEAT_IVA		0
#define		FEAT_IVA_NONE		1

#define OMAP3_L2CACHE_SHIFT		10
#define OMAP3_L2CACHE_MASK		(3 &lt;&lt; OMAP3_L2CACHE_SHIFT)
#define		FEAT_L2CACHE_NONE	0
#define		FEAT_L2CACHE_64KB	1
#define		FEAT_L2CACHE_128KB	2
#define		FEAT_L2CACHE_256KB	3

#define OMAP3_ISP_SHIFT			5
#define OMAP3_ISP_MASK			(1 &lt;&lt; OMAP3_ISP_SHIFT)
#define		FEAT_ISP		0
#define		FEAT_ISP_NONE		1

#define OMAP3_NEON_SHIFT		4
#define OMAP3_NEON_MASK			(1 &lt;&lt; OMAP3_NEON_SHIFT)
#define		FEAT_NEON		0
#define		FEAT_NEON_NONE		1


#ifndef __ASSEMBLY__
#ifdef CONFIG_ARCH_OMAP2PLUS
extern void __iomem *omap_ctrl_base_get(void);
extern u8 omap_ctrl_readb(u16 offset);
extern u16 omap_ctrl_readw(u16 offset);
extern u32 omap_ctrl_readl(u16 offset);
extern u32 omap4_ctrl_pad_readl(u16 offset);
extern void omap_ctrl_writeb(u8 val, u16 offset);
extern void omap_ctrl_writew(u16 val, u16 offset);
extern void omap_ctrl_writel(u32 val, u16 offset);
extern void omap4_ctrl_pad_writel(u32 val, u16 offset);

extern void omap3_save_scratchpad_contents(void);
extern void omap3_clear_scratchpad_contents(void);
extern u32 *get_restore_pointer(void);
extern u32 *get_es3_restore_pointer(void);
extern u32 omap3_arm_context[128];
extern void omap3_control_save_context(void);
extern void omap3_control_restore_context(void);

#else
#define omap_ctrl_base_get()		0
#define omap_ctrl_readb(x)		0
#define omap_ctrl_readw(x)		0
#define omap_ctrl_readl(x)		0
#define omap4_ctrl_pad_readl(x)		0
#define omap_ctrl_writeb(x, y)		WARN_ON(1)
#define omap_ctrl_writew(x, y)		WARN_ON(1)
#define omap_ctrl_writel(x, y)		WARN_ON(1)
#define omap4_ctrl_pad_writel(x, y)	WARN_ON(1)
#endif
#endif	/* __ASSEMBLY__ */

#endif /* __ARCH_ARM_MACH_OMAP2_CONTROL_H */

</textarea>
    </div>

    <div class="js-commit-preview">
    </div>
  </div><!-- /.file -->

  <div class="file-commit-form">
    <div class="too-long-message">Great commit summaries are 50 characters or less</div>
    <label for="summary" class="commit-message-summary-label">Commit summary:</label>
    <input type="text" class="commit-message-summary" placeholder="Update arch/arm/mach-omap2/control.h" name="message"></input>

    <label for="message" class="commit-message-label">Extended description: <small>(optional)</small></label>
    <textarea name="description" class="commit-message"></textarea>

    <div class="form-actions">
      <a href="/samno1607/PK2-O3D/blob/master/arch/arm/mach-omap2/control.h" class="button classy danger cancel">Cancel</a>
        <button type="submit" class="classy js-blob-edit-submit" disabled>Commit Changes</button>
    </div>
  </div>
</form>
<script defer="defer" src="https://a248.e.akamai.net/assets.github.com/assets/editor-efdaeeae1d115554d40742fc9ddce9e1c3ff918e.js" type="text/javascript"></script>

  </div>


        </div>
      </div>
      <div class="context-overlay"></div>
    </div>

      <div id="footer-push"></div><!-- hack for sticky footer -->
    </div><!-- end of wrapper - hack for sticky footer -->

      <!-- footer -->
      <div id="footer" >
        
  <div class="upper_footer">
     <div class="container clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://enterprise.github.com/">GitHub Enterprise</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Clients</h4>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://windows.github.com/">GitHub for Windows</a></li>
         <li><a href="http://eclipse.github.com/">GitHub for Eclipse</a></li>
         <li><a href="http://mobile.github.com/">GitHub Mobile Apps</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://get.gaug.es/">Gauges: Web analytics</a></li>
         <li><a href="http://speakerdeck.com">Speaker Deck: Presentations</a></li>
         <li><a href="https://gist.github.com">Gist: Code snippets</a></li>

         <h4 class="second">Extras</h4>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="container clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2012 <span title="0.12740s from fe19.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

  </div><!-- /.site -->
</div><!-- /.lower_footer -->

      </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style='display:none'>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last js-hidden-pane" style='display:none'>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
        <dd>Submit comment</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> shift p</dt>
        <dd>Preview comment</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div class="js-hidden-pane" style='display:none'>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> shift p</dt>
          <dd>Preview comment</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div class="js-hidden-pane" style='display:none'>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div class="js-hidden-pane" style='display:none'>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div class="js-hidden-pane" >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first js-hidden-pane" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>

  <div class="js-hidden-pane" style='display:none'>
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first">
        <h3>Browsing Commits</h3>
        <dl class="keyboard-mappings">
          <dt><span class="platform-mac">⌘</span><span class="platform-other">ctrl</span> <em>+</em> enter</dt>
          <dd>Submit comment</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>escape</dt>
          <dd>Close form</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>p</dt>
          <dd>Parent commit</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o</dt>
          <dd>Other parent commit</dd>
        </dl>
      </div>
    </div>
  </div>

  <div class="js-hidden-pane" style='display:none'>
    <div class="rule"></div>
    <h3>Notifications</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open notification</dd>
        </dl>
      </div><!-- /.column.first -->

      <div class="column second">
        <dl class="keyboard-mappings">
          <dt>e <em>or</em> shift i <em>or</em> y</dt>
          <dd>Mark as read</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift m</dt>
          <dd>Mute thread</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:

> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>


    <div id="ajax-error-message">
      <span class="mini-icon mini-icon-exclamation"></span>
      Something went wrong with that request. Please try again.
      <a href="#" class="ajax-error-dismiss">Dismiss</a>
    </div>

    <div id="logo-popup">
      <h2>Looking for the GitHub logo?</h2>
      <ul>
        <li>
          <h4>GitHub Logo</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip"><img alt="Github_logo" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/github_logo.png?1340935010" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/GitHub_Logos.zip" class="minibutton btn-download download">Download</a>
        </li>
        <li>
          <h4>The Octocat</h4>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip"><img alt="Octocat" src="https://a248.e.akamai.net/assets.github.com/images/modules/about_page/octocat.png?1340935010" /></a>
          <a href="http://github-media-downloads.s3.amazonaws.com/Octocats.zip" class="minibutton btn-download download">Download</a>
        </li>
      </ul>
    </div>

    
    
    <span id='server_response_time' data-time='0.13034' data-host='fe19'></span>
  </body>
</html>


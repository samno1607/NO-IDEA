  


<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# githubog: http://ogp.me/ns/fb/githubog#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Editing PK2-O3D/arch/arm/mach-omap2/control.c at master · samno1607/PK2-O3D</title>
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
                    <a href="/samno1607/PK2-O3D/edit/master/arch/arm/mach-omap2/control.c" class="js-navigation-open" data-name="master" rel="nofollow">master</a>
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
  <li><a class="minibutton" href="/samno1607/PK2-O3D/blob/master/arch/arm/mach-omap2/control.c">Back to source view</a></li>
</ul>

<div class="breadcrumb" data-path="arch/arm/mach-omap2/control.c/">
  <b itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d" class="js-rewrite-sha" itemprop="url"><span itemprop="title">PK2-O3D</span></a></b> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch" class="js-rewrite-sha" itemscope="url"><span itemprop="title">arch</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch/arm" class="js-rewrite-sha" itemscope="url"><span itemprop="title">arm</span></a></span> / <span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/samno1607/PK2-O3D/tree/b5dcfd8e95f4fe5423e2d804b6a02eff4af3f66d/arch/arm/mach-omap2" class="js-rewrite-sha" itemscope="url"><span itemprop="title">mach-omap2</span></a></span> / <strong class="final-path">control.c</strong> <span class="js-clippy mini-icon mini-icon-clippy " data-clipboard-text="arch/arm/mach-omap2/control.c" data-copied-hint="copied!" data-copy-hint="copy to clipboard"></span>
</div>

  <div id="files">
    
<div class="js-blob-edit-progress large-loading-area">
  <img alt="Octocat-spinner-64" src="https://a248.e.akamai.net/assets.github.com/images/spinners/octocat-spinner-64.gif?1340935010" />
</div>

<form accept-charset="UTF-8" action="/samno1607/PK2-O3D/tree-save/master/arch/arm/mach-omap2/control.c" class="js-blob-edit-form" method="post" style="display:none"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="QngfAcCIhWc/gkRPBHoFMy4TviKRTZRnI1IRoilUQK0=" /></div>  <input id="utc_offset" type="hidden" name="utc_offset">
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
      <textarea class="file-editor-textarea" rows="35" name="value" data-language="C" data-filename="control.c" autofocus>/*
 * OMAP2/3 System Control Module register access
 *
 * Copyright (C) 2007 Texas Instruments, Inc.
 * Copyright (C) 2007 Nokia Corporation
 *
 * Written by Paul Walmsley
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#undef DEBUG

#include &lt;linux/kernel.h&gt;
#include &lt;linux/io.h&gt;

#include &lt;plat/common.h&gt;
#include &lt;plat/control.h&gt;
#include &lt;plat/sdrc.h&gt;
#include &quot;cm-regbits-34xx.h&quot;
#include &quot;prm-regbits-34xx.h&quot;
#include &quot;cm.h&quot;
#include &quot;prm.h&quot;
#include &quot;sdrc.h&quot;
#include &quot;pm.h&quot;

static void __iomem *omap2_ctrl_base;
static void __iomem *omap4_ctrl_pad_base;

#if defined(CONFIG_ARCH_OMAP3) &amp;&amp; defined(CONFIG_PM)
struct omap3_scratchpad {
	u32 boot_config_ptr;
	u32 public_restore_ptr;
	u32 secure_ram_restore_ptr;
	u32 sdrc_module_semaphore;
	u32 prcm_block_offset;
	u32 sdrc_block_offset;
};

struct omap3_scratchpad_prcm_block {
	u32 prm_clksrc_ctrl;
	u32 prm_clksel;
	u32 cm_clksel_core;
	u32 cm_clksel_wkup;
	u32 cm_clken_pll;
	u32 cm_autoidle_pll;
	u32 cm_clksel1_pll;
	u32 cm_clksel2_pll;
	u32 cm_clksel3_pll;
	u32 cm_clken_pll_mpu;
	u32 cm_autoidle_pll_mpu;
	u32 cm_clksel1_pll_mpu;
	u32 cm_clksel2_pll_mpu;
	u32 prcm_block_size;
};

struct omap3_scratchpad_sdrc_block {
	u16 sysconfig;
	u16 cs_cfg;
	u16 sharing;
	u16 err_type;
	u32 dll_a_ctrl;
	u32 dll_b_ctrl;
	u32 power;
	u32 cs_0;
	u32 mcfg_0;
	u16 mr_0;
	u16 emr_1_0;
	u16 emr_2_0;
	u16 emr_3_0;
	u32 actim_ctrla_0;
	u32 actim_ctrlb_0;
	u32 rfr_ctrl_0;
	u32 cs_1;
	u32 mcfg_1;
	u16 mr_1;
	u16 emr_1_1;
	u16 emr_2_1;
	u16 emr_3_1;
	u32 actim_ctrla_1;
	u32 actim_ctrlb_1;
	u32 rfr_ctrl_1;
	u16 dcdl_1_ctrl;
	u16 dcdl_2_ctrl;
	u32 flags;
	u32 block_size;
};

void *omap3_secure_ram_storage;

/*
 * This is used to store ARM registers in SDRAM before attempting
 * an MPU OFF. The save and restore happens from the SRAM sleep code.
 * The address is stored in scratchpad, so that it can be used
 * during the restore path.
 */
u32 omap3_arm_context[128];

struct omap3_control_regs {
	u32 sysconfig;
	u32 devconf0;
	u32 mem_dftrw0;
	u32 mem_dftrw1;
	u32 msuspendmux_0;
	u32 msuspendmux_1;
	u32 msuspendmux_2;
	u32 msuspendmux_3;
	u32 msuspendmux_4;
	u32 msuspendmux_5;
	u32 sec_ctrl;
	u32 devconf1;
	u32 csirxfe;
	u32 iva2_bootaddr;
	u32 iva2_bootmod;
	u32 debobs_0;
	u32 debobs_1;
	u32 debobs_2;
	u32 debobs_3;
	u32 debobs_4;
	u32 debobs_5;
	u32 debobs_6;
	u32 debobs_7;
	u32 debobs_8;
	u32 prog_io0;
	u32 prog_io1;
	u32 dss_dpll_spreading;
	u32 core_dpll_spreading;
	u32 per_dpll_spreading;
	u32 usbhost_dpll_spreading;
	u32 pbias_lite;
	u32 temp_sensor;
	u32 sramldo4;
	u32 sramldo5;
	u32 csi;
};

static struct omap3_control_regs control_context;
#endif /* CONFIG_ARCH_OMAP3 &amp;&amp; CONFIG_PM */

#define OMAP_CTRL_REGADDR(reg)		(omap2_ctrl_base + (reg))
#define OMAP4_CTRL_PAD_REGADDR(reg)	(omap4_ctrl_pad_base + (reg))

void __init omap2_set_globals_control(struct omap_globals *omap2_globals)
{
	/* Static mapping, never released */
	if (omap2_globals-&gt;ctrl) {
		omap2_ctrl_base = ioremap(omap2_globals-&gt;ctrl, SZ_4K);
		WARN_ON(!omap2_ctrl_base);
	}

	/* Static mapping, never released */
	if (omap2_globals-&gt;ctrl_pad) {
		omap4_ctrl_pad_base = ioremap(omap2_globals-&gt;ctrl_pad, SZ_4K);
		WARN_ON(!omap4_ctrl_pad_base);
	}
}

void __iomem *omap_ctrl_base_get(void)
{
	return omap2_ctrl_base;
}

u8 omap_ctrl_readb(u16 offset)
{
	return __raw_readb(OMAP_CTRL_REGADDR(offset));
}

u16 omap_ctrl_readw(u16 offset)
{
	return __raw_readw(OMAP_CTRL_REGADDR(offset));
}

u32 omap_ctrl_readl(u16 offset)
{
	return __raw_readl(OMAP_CTRL_REGADDR(offset));
}

void omap_ctrl_writeb(u8 val, u16 offset)
{
	__raw_writeb(val, OMAP_CTRL_REGADDR(offset));
}

void omap_ctrl_writew(u16 val, u16 offset)
{
	__raw_writew(val, OMAP_CTRL_REGADDR(offset));
}

void omap_ctrl_writel(u32 val, u16 offset)
{
	__raw_writel(val, OMAP_CTRL_REGADDR(offset));
}

/*
 * On OMAP4 control pad are not addressable from control
 * core base. So the common omap_ctrl_read/write APIs breaks
 * Hence export separate APIs to manage the omap4 pad control
 * registers. This APIs will work only for OMAP4
 */

u32 omap4_ctrl_pad_readl(u16 offset)
{
	return __raw_readl(OMAP4_CTRL_PAD_REGADDR(offset));
}

void omap4_ctrl_pad_writel(u32 val, u16 offset)
{
	__raw_writel(val, OMAP4_CTRL_PAD_REGADDR(offset));
}

#if defined(CONFIG_ARCH_OMAP3) &amp;&amp; defined(CONFIG_PM)
/*
 * Clears the scratchpad contents in case of cold boot-
 * called during bootup
 */
void omap3_clear_scratchpad_contents(void)
{
	u32 max_offset = OMAP343X_SCRATCHPAD_ROM_OFFSET;
	void __iomem *v_addr;
	u32 offset = 0;
	v_addr = OMAP2_L4_IO_ADDRESS(OMAP343X_SCRATCHPAD_ROM);
	if (prm_read_mod_reg(OMAP3430_GR_MOD, OMAP3_PRM_RSTST_OFFSET) &amp;
	    OMAP3430_GLOBAL_COLD_RST_MASK) {
		for ( ; offset &lt;= max_offset; offset += 0x4)
			__raw_writel(0x0, (v_addr + offset));
		prm_set_mod_reg_bits(OMAP3430_GLOBAL_COLD_RST_MASK,
				     OMAP3430_GR_MOD,
				     OMAP3_PRM_RSTST_OFFSET);
	}
}

/* Populate the scratchpad structure with restore structure */
void omap3_save_scratchpad_contents(void)
{
	void  __iomem *scratchpad_address;
	u32 arm_context_addr;
	struct omap3_scratchpad scratchpad_contents;
	struct omap3_scratchpad_prcm_block prcm_block_contents;
	struct omap3_scratchpad_sdrc_block sdrc_block_contents;

	/* Populate the Scratchpad contents */
	scratchpad_contents.boot_config_ptr = 0x0;
	if (omap_rev() != OMAP3430_REV_ES3_0 &amp;&amp;
					omap_rev() != OMAP3430_REV_ES3_1)
		scratchpad_contents.public_restore_ptr =
			virt_to_phys(get_restore_pointer());
	else
		scratchpad_contents.public_restore_ptr =
			virt_to_phys(get_es3_restore_pointer());
	if (omap_type() == OMAP2_DEVICE_TYPE_GP)
		scratchpad_contents.secure_ram_restore_ptr = 0x0;
	else
		scratchpad_contents.secure_ram_restore_ptr =
			(u32) __pa(omap3_secure_ram_storage);
	scratchpad_contents.sdrc_module_semaphore = 0x0;
	scratchpad_contents.prcm_block_offset = 0x2C;
	scratchpad_contents.sdrc_block_offset = 0x64;

	/* Populate the PRCM block contents */
	prcm_block_contents.prm_clksrc_ctrl = prm_read_mod_reg(OMAP3430_GR_MOD,
			OMAP3_PRM_CLKSRC_CTRL_OFFSET);
	prcm_block_contents.prm_clksel = prm_read_mod_reg(OMAP3430_CCR_MOD,
			OMAP3_PRM_CLKSEL_OFFSET);
	prcm_block_contents.cm_clksel_core =
			cm_read_mod_reg(CORE_MOD, CM_CLKSEL);
	prcm_block_contents.cm_clksel_wkup =
			cm_read_mod_reg(WKUP_MOD, CM_CLKSEL);
	prcm_block_contents.cm_clken_pll =
			cm_read_mod_reg(PLL_MOD, CM_CLKEN);
	prcm_block_contents.cm_autoidle_pll =
			cm_read_mod_reg(PLL_MOD, OMAP3430_CM_AUTOIDLE_PLL);
	prcm_block_contents.cm_clksel1_pll =
			cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL1_PLL);
	prcm_block_contents.cm_clksel2_pll =
			cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL2_PLL);
	prcm_block_contents.cm_clksel3_pll =
			cm_read_mod_reg(PLL_MOD, OMAP3430_CM_CLKSEL3);
	prcm_block_contents.cm_clken_pll_mpu =
			cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKEN_PLL);
	prcm_block_contents.cm_autoidle_pll_mpu =
			cm_read_mod_reg(MPU_MOD, OMAP3430_CM_AUTOIDLE_PLL);
	prcm_block_contents.cm_clksel1_pll_mpu =
			cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL1_PLL);
	prcm_block_contents.cm_clksel2_pll_mpu =
			cm_read_mod_reg(MPU_MOD, OMAP3430_CM_CLKSEL2_PLL);
	prcm_block_contents.prcm_block_size = 0x0;

	/* Populate the SDRC block contents */
	sdrc_block_contents.sysconfig =
			(sdrc_read_reg(SDRC_SYSCONFIG) &amp; 0xFFFF);
	sdrc_block_contents.cs_cfg =
			(sdrc_read_reg(SDRC_CS_CFG) &amp; 0xFFFF);
	sdrc_block_contents.sharing =
			(sdrc_read_reg(SDRC_SHARING) &amp; 0xFFFF);
	sdrc_block_contents.err_type =
			(sdrc_read_reg(SDRC_ERR_TYPE) &amp; 0xFFFF);
	sdrc_block_contents.dll_a_ctrl = sdrc_read_reg(SDRC_DLLA_CTRL);
	sdrc_block_contents.dll_b_ctrl = 0x0;
	/*
	 * Due to a OMAP3 errata (1.142), on EMU/HS devices SRDC should
	 * be programed to issue automatic self refresh on timeout
	 * of AUTO_CNT = 1 prior to any transition to OFF mode.
	 */
	if ((omap_type() != OMAP2_DEVICE_TYPE_GP)
			&amp;&amp; (omap_rev() &gt;= OMAP3430_REV_ES3_0))
		sdrc_block_contents.power = (sdrc_read_reg(SDRC_POWER) &amp;
				~(SDRC_POWER_AUTOCOUNT_MASK|
				SDRC_POWER_CLKCTRL_MASK)) |
				(1 &lt;&lt; SDRC_POWER_AUTOCOUNT_SHIFT) |
				SDRC_SELF_REFRESH_ON_AUTOCOUNT;
	else
		sdrc_block_contents.power = sdrc_read_reg(SDRC_POWER);

	sdrc_block_contents.cs_0 = 0x0;
	sdrc_block_contents.mcfg_0 = sdrc_read_reg(SDRC_MCFG_0);
	sdrc_block_contents.mr_0 = (sdrc_read_reg(SDRC_MR_0) &amp; 0xFFFF);
	sdrc_block_contents.emr_1_0 = 0x0;
	sdrc_block_contents.emr_2_0 = 0x0;
	sdrc_block_contents.emr_3_0 = 0x0;
	sdrc_block_contents.actim_ctrla_0 =
			sdrc_read_reg(SDRC_ACTIM_CTRL_A_0);
	sdrc_block_contents.actim_ctrlb_0 =
			sdrc_read_reg(SDRC_ACTIM_CTRL_B_0);
	sdrc_block_contents.rfr_ctrl_0 =
			sdrc_read_reg(SDRC_RFR_CTRL_0);
	sdrc_block_contents.cs_1 = 0x0;
	sdrc_block_contents.mcfg_1 = sdrc_read_reg(SDRC_MCFG_1);
	sdrc_block_contents.mr_1 = sdrc_read_reg(SDRC_MR_1) &amp; 0xFFFF;
	sdrc_block_contents.emr_1_1 = 0x0;
	sdrc_block_contents.emr_2_1 = 0x0;
	sdrc_block_contents.emr_3_1 = 0x0;
	sdrc_block_contents.actim_ctrla_1 =
			sdrc_read_reg(SDRC_ACTIM_CTRL_A_1);
	sdrc_block_contents.actim_ctrlb_1 =
			sdrc_read_reg(SDRC_ACTIM_CTRL_B_1);
	sdrc_block_contents.rfr_ctrl_1 =
			sdrc_read_reg(SDRC_RFR_CTRL_1);
	sdrc_block_contents.dcdl_1_ctrl = 0x0;
	sdrc_block_contents.dcdl_2_ctrl = 0x0;
	sdrc_block_contents.flags = 0x0;
	sdrc_block_contents.block_size = 0x0;

	arm_context_addr = virt_to_phys(omap3_arm_context);

	/* Copy all the contents to the scratchpad location */
	scratchpad_address = OMAP2_L4_IO_ADDRESS(OMAP343X_SCRATCHPAD);
	memcpy_toio(scratchpad_address, &amp;scratchpad_contents,
		 sizeof(scratchpad_contents));
	/* Scratchpad contents being 32 bits, a divide by 4 done here */
	memcpy_toio(scratchpad_address +
		scratchpad_contents.prcm_block_offset,
		&amp;prcm_block_contents, sizeof(prcm_block_contents));
	memcpy_toio(scratchpad_address +
		scratchpad_contents.sdrc_block_offset,
		&amp;sdrc_block_contents, sizeof(sdrc_block_contents));
	/*
	 * Copies the address of the location in SDRAM where ARM
	 * registers get saved during a MPU OFF transition.
	 */
	memcpy_toio(scratchpad_address +
		scratchpad_contents.sdrc_block_offset +
		sizeof(sdrc_block_contents), &amp;arm_context_addr, 4);
}

void omap3_control_save_context(void)
{
	control_context.sysconfig = omap_ctrl_readl(OMAP2_CONTROL_SYSCONFIG);
	control_context.devconf0 = omap_ctrl_readl(OMAP2_CONTROL_DEVCONF0);
	control_context.mem_dftrw0 =
			omap_ctrl_readl(OMAP343X_CONTROL_MEM_DFTRW0);
	control_context.mem_dftrw1 =
			omap_ctrl_readl(OMAP343X_CONTROL_MEM_DFTRW1);
	control_context.msuspendmux_0 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_0);
	control_context.msuspendmux_1 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_1);
	control_context.msuspendmux_2 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_2);
	control_context.msuspendmux_3 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_3);
	control_context.msuspendmux_4 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_4);
	control_context.msuspendmux_5 =
			omap_ctrl_readl(OMAP2_CONTROL_MSUSPENDMUX_5);
	control_context.sec_ctrl = omap_ctrl_readl(OMAP2_CONTROL_SEC_CTRL);
	control_context.devconf1 = omap_ctrl_readl(OMAP343X_CONTROL_DEVCONF1);
	control_context.csirxfe = omap_ctrl_readl(OMAP343X_CONTROL_CSIRXFE);
	control_context.iva2_bootaddr =
			omap_ctrl_readl(OMAP343X_CONTROL_IVA2_BOOTADDR);
	control_context.iva2_bootmod =
			omap_ctrl_readl(OMAP343X_CONTROL_IVA2_BOOTMOD);
	control_context.debobs_0 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(0));
	control_context.debobs_1 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(1));
	control_context.debobs_2 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(2));
	control_context.debobs_3 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(3));
	control_context.debobs_4 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(4));
	control_context.debobs_5 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(5));
	control_context.debobs_6 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(6));
	control_context.debobs_7 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(7));
	control_context.debobs_8 = omap_ctrl_readl(OMAP343X_CONTROL_DEBOBS(8));
	control_context.prog_io0 = omap_ctrl_readl(OMAP343X_CONTROL_PROG_IO0);
	control_context.prog_io1 = omap_ctrl_readl(OMAP343X_CONTROL_PROG_IO1);
	control_context.dss_dpll_spreading =
			omap_ctrl_readl(OMAP343X_CONTROL_DSS_DPLL_SPREADING);
	control_context.core_dpll_spreading =
			omap_ctrl_readl(OMAP343X_CONTROL_CORE_DPLL_SPREADING);
	control_context.per_dpll_spreading =
			omap_ctrl_readl(OMAP343X_CONTROL_PER_DPLL_SPREADING);
	control_context.usbhost_dpll_spreading =
		omap_ctrl_readl(OMAP343X_CONTROL_USBHOST_DPLL_SPREADING);
	control_context.pbias_lite =
			omap_ctrl_readl(OMAP343X_CONTROL_PBIAS_LITE);
	control_context.temp_sensor =
			omap_ctrl_readl(OMAP343X_CONTROL_TEMP_SENSOR);
	control_context.sramldo4 = omap_ctrl_readl(OMAP343X_CONTROL_SRAMLDO4);
	control_context.sramldo5 = omap_ctrl_readl(OMAP343X_CONTROL_SRAMLDO5);
	control_context.csi = omap_ctrl_readl(OMAP343X_CONTROL_CSI);
	return;
}

void omap3_control_restore_context(void)
{
	omap_ctrl_writel(control_context.sysconfig, OMAP2_CONTROL_SYSCONFIG);
	omap_ctrl_writel(control_context.devconf0, OMAP2_CONTROL_DEVCONF0);
	omap_ctrl_writel(control_context.mem_dftrw0,
					OMAP343X_CONTROL_MEM_DFTRW0);
	omap_ctrl_writel(control_context.mem_dftrw1,
					OMAP343X_CONTROL_MEM_DFTRW1);
	omap_ctrl_writel(control_context.msuspendmux_0,
					OMAP2_CONTROL_MSUSPENDMUX_0);
	omap_ctrl_writel(control_context.msuspendmux_1,
					OMAP2_CONTROL_MSUSPENDMUX_1);
	omap_ctrl_writel(control_context.msuspendmux_2,
					OMAP2_CONTROL_MSUSPENDMUX_2);
	omap_ctrl_writel(control_context.msuspendmux_3,
					OMAP2_CONTROL_MSUSPENDMUX_3);
	omap_ctrl_writel(control_context.msuspendmux_4,
					OMAP2_CONTROL_MSUSPENDMUX_4);
	omap_ctrl_writel(control_context.msuspendmux_5,
					OMAP2_CONTROL_MSUSPENDMUX_5);
	omap_ctrl_writel(control_context.sec_ctrl, OMAP2_CONTROL_SEC_CTRL);
	omap_ctrl_writel(control_context.devconf1, OMAP343X_CONTROL_DEVCONF1);
	omap_ctrl_writel(control_context.csirxfe, OMAP343X_CONTROL_CSIRXFE);
	omap_ctrl_writel(control_context.iva2_bootaddr,
					OMAP343X_CONTROL_IVA2_BOOTADDR);
	omap_ctrl_writel(control_context.iva2_bootmod,
					OMAP343X_CONTROL_IVA2_BOOTMOD);
	omap_ctrl_writel(control_context.debobs_0, OMAP343X_CONTROL_DEBOBS(0));
	omap_ctrl_writel(control_context.debobs_1, OMAP343X_CONTROL_DEBOBS(1));
	omap_ctrl_writel(control_context.debobs_2, OMAP343X_CONTROL_DEBOBS(2));
	omap_ctrl_writel(control_context.debobs_3, OMAP343X_CONTROL_DEBOBS(3));
	omap_ctrl_writel(control_context.debobs_4, OMAP343X_CONTROL_DEBOBS(4));
	omap_ctrl_writel(control_context.debobs_5, OMAP343X_CONTROL_DEBOBS(5));
	omap_ctrl_writel(control_context.debobs_6, OMAP343X_CONTROL_DEBOBS(6));
	omap_ctrl_writel(control_context.debobs_7, OMAP343X_CONTROL_DEBOBS(7));
	omap_ctrl_writel(control_context.debobs_8, OMAP343X_CONTROL_DEBOBS(8));
	omap_ctrl_writel(control_context.prog_io0, OMAP343X_CONTROL_PROG_IO0);
	omap_ctrl_writel(control_context.prog_io1, OMAP343X_CONTROL_PROG_IO1);
	omap_ctrl_writel(control_context.dss_dpll_spreading,
					OMAP343X_CONTROL_DSS_DPLL_SPREADING);
	omap_ctrl_writel(control_context.core_dpll_spreading,
					OMAP343X_CONTROL_CORE_DPLL_SPREADING);
	omap_ctrl_writel(control_context.per_dpll_spreading,
					OMAP343X_CONTROL_PER_DPLL_SPREADING);
	omap_ctrl_writel(control_context.usbhost_dpll_spreading,
				OMAP343X_CONTROL_USBHOST_DPLL_SPREADING);
	omap_ctrl_writel(control_context.pbias_lite,
					OMAP343X_CONTROL_PBIAS_LITE);
	omap_ctrl_writel(control_context.temp_sensor,
					OMAP343X_CONTROL_TEMP_SENSOR);
	omap_ctrl_writel(control_context.sramldo4, OMAP343X_CONTROL_SRAMLDO4);
	omap_ctrl_writel(control_context.sramldo5, OMAP343X_CONTROL_SRAMLDO5);
	omap_ctrl_writel(control_context.csi, OMAP343X_CONTROL_CSI);
	return;
}
#endif /* CONFIG_ARCH_OMAP3 &amp;&amp; CONFIG_PM */
</textarea>
    </div>

    <div class="js-commit-preview">
    </div>
  </div><!-- /.file -->

  <div class="file-commit-form">
    <div class="too-long-message">Great commit summaries are 50 characters or less</div>
    <label for="summary" class="commit-message-summary-label">Commit summary:</label>
    <input type="text" class="commit-message-summary" placeholder="Update arch/arm/mach-omap2/control.c" name="message"></input>

    <label for="message" class="commit-message-label">Extended description: <small>(optional)</small></label>
    <textarea name="description" class="commit-message"></textarea>

    <div class="form-actions">
      <a href="/samno1607/PK2-O3D/blob/master/arch/arm/mach-omap2/control.c" class="button classy danger cancel">Cancel</a>
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

      <p>&copy; 2012 <span title="0.09748s from fe19.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
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

    
    
    <span id='server_response_time' data-time='0.10657' data-host='fe19'></span>
  </body>
</html>

